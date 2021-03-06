#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// An adjacency list. Each adjList[i] holds a all the friends of node i.
// The first int is the vertex of the friend, the second int is the edge weight.

    
// Given an Adjacency List, find all shortest paths from "start" to all other vertices.
vector<int> DijkstraSP(vector< vector<pair<int, int> > > &adjList, int &start){
    cout << "\nGetting the shortest path from " << start << " to all other nodes.\n";
    vector<int> dist;
    
    // Initialize all source->vertex as infinite.
    int n = adjList.size();
    for(int i = 0; i < n; i++)
        {
        dist.push_back(1000000007); // Define "infinity" as necessary by constraints.
        }
        
    // Create a PQ.
    priority_queue<pair<int, int>, vector< pair<int, int> >, greater<pair<int, int> > > pq;
    
    // Add source to pq, where distance is 0.
    pq.push(make_pair(start, 0));
    dist[start] = 0;
    
    // While pq isn't empty...
    while(pq.empty() == false)
        {
        // Get min distance vertex from pq. (Call it u.)
        int u = pq.top().first;
        pq.pop();
        
        // Visit all of u's friends. For each one (called v)....
        for(int i = 0; i < adjList[u].size(); i++)
            {
            int v = adjList[u][i].first;
            int weight = adjList[u][i].second;
            
            // If the distance to v is shorter by going through u...
            if(dist[v] > dist[u] + weight)
                {
                // Update the distance of v.
                dist[v] = dist[u] + weight;
                // Insert v into the pq. 
                pq.push(make_pair(v, dist[v]));
                }
            }
        }
    
    return dist;
}
    
void PrintShortestPath(vector<int> &dist, int &start)
    {
    cout << "\nPrinting the shortest paths for node " << start << ".\n";
    for(int i = 0; i < dist.size(); i++)
        {
        cout << "The distance from node " << start << " to node " << i << " is: " << dist[i] << endl;
        }
    }
    
int main(int argc, char** argv) {
    cout << "Program started.\n";
    
    // Our adjacency list.
    vector< vector<pair<int, int> > > adjList;
    vector< pair <int,int> > vPairs;
    
    // We have 7 vertices, so initialize 7 rows.
    int n, c, r;
    cin >> n;

    int appearance[n];

    for (int i = 0; i < n; i++){
        cin >> appearance[i];
    }

    cin >> c;
    cin >> r;

    int inputMatrix[r][c];

    for (int i = 0; i < r; i++){
      for(int j = 0; j < c; j++){
        cin >> inputMatrix[i][j];
      }
    }

    //The first int is the vertex of the friend, the second int is the edge weight.
    for (int i = 0; i < r; i++)
      vPairs.push_back(make_pair(inputMatrix[i][0],inputMatrix[i][1]));

    for(int i = 0; i < n; i++){
      vector<pair<int, int> > row;
      adjList.push_back(row);
    }

    //Each adjList[i] holds a all the friends of node i.
    int p = 0;
    for(int i = 0; i < n; i++)
      for(int j = 0; j < appearance[i]; j++){
        adjList[i].push_back(vPairs[p]);
        p++;
      }

    int node = 0;
    vector<int> dist = DijkstraSP(adjList, node);
    
    // Print the list.
    PrintShortestPath(dist, node);
    
    cout << "Program ended.\n";

    return 0;
}