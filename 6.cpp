#include <iostream> 
#include <vector> 
#include <queue> 
using namespace std; 
 
// Landmarks from Notre Dame's campus[4] 
const vector<string> landmarks = { 
    "Golden Dome",       // 0 
    "Touchdown Jesus",   // 1 
    "Grotto",            // 2 
    "Basilica",          // 3 
    "Notre Dame Stadium",// 4 
    "South Dining Hall"  // 5 
}; 
 
// Adjacency matrix for DFS (undirected graph) 
const int matrix[6][6] = { 
    {0,0,0,1,1,0},  // Golden Dome -> Basilica, Stadium 
    {0,0,0,1,1,0},  // Touchdown Jesus -> Basilica, Stadium 
    {0,0,0,1,0,1},  // Grotto -> Basilica, South Dining Hall 
    {1,1,1,0,0,1},  // Basilica -> All major connections 
    {1,1,0,0,0,0},  // Stadium -> Golden Dome, Touchdown Jesus 
    {0,0,1,1,0,0}   // South Dining Hall -> Grotto, Basilica 
}; 
 
// Adjacency list for BFS 
vector<vector<int>> adjList = { 
    {3,4},        // Golden Dome 
    {3,4},        // Touchdown Jesus 
    {3,5},        // Grotto 
    {0,1,2,5},    // Basilica 
    {0,1},        // Stadium 
    {2,3}         // South Dining Hall 
}; 
 
// DFS using adjacency matrix 
void dfs(int node, vector<bool>& visited) { 
    visited[node] = true; 
    cout << landmarks[node] << " -> "; 
    for(int i=0; i<6; i++) { 
        if(matrix[node][i] && !visited[i]) { 
            dfs(i, visited); 
        } 
    } 
} 
 
// BFS using adjacency list 
void bfs(int start) { 
    vector<bool> visited(6, false); 
    queue<int> q; 
    q.push(start); 
    visited[start] = true; 
     
    while(!q.empty()) { 
        int current = q.front(); 
        q.pop(); 
        cout << landmarks[current] << " -> "; 
         
        for(int neighbor : adjList[current]) { 
            if(!visited[neighbor]) { 
                visited[neighbor] = true; 
                q.push(neighbor); 
            } 
        } 
    } 
} 
 
int main() { 
    vector<bool> dfsVisited(6, false); 
     
    cout << "DFS traversal starting from Golden Dome:\n"; 
    dfs(0, dfsVisited); 
     
    cout << "\n\nBFS traversal starting from Golden Dome:\n"; 
    bfs(0); 
     
    return 0; 
} 