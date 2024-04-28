#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <string>

using namespace std;
void DFS(map<int,vector<int>>&adjlist,vector<int>&visited,int node){
    visited[node]=1;
    cout<<node<<" ";
    for(auto it:adjlist[node]){
        if(!visited[it]){
            DFS(adjlist,visited,it);
        }
    }
}
void BFS(map<int,vector<int>>& adjlist, vector<int>& visited, int node){
    queue<int> q;
    q.push(node);
    visited[node] = 1; // Mark the starting node as visited
    while (!q.empty()) {
        int current_node = q.front();
        q.pop();
        cout << current_node << " ";
        for (auto it : adjlist[current_node]) {
            if (!visited[it]) {
                q.push(it);
                visited[it] = 1; // Mark the adjacent node as visited
            }
        }
    }
}




int main() {
    // Define landmarks as nodes
    map<string, int> landmarks = {
        {"library", 0},
        {"cafeteria", 1},
        {"gym", 2},
        {"park", 3},
        {"auditorium", 4}
    };

    // Create adjacency matrix for DFS
    vector<vector<int>> adjMatrix = {
        {0, 1, 1, 0, 0},
        {1, 0, 0, 1, 1},
        {1, 0, 0, 0, 1},
        {0, 1, 0, 0, 0},
        {0, 1, 1, 0, 0}
    };

    // Create adjacency list for BFS
    map<int, vector<int>> adjList;
    adjList[0] = {1, 2};
    adjList[1] = {0, 3, 4};
    adjList[2] = {0, 4};
    adjList[3] = {1};
    adjList[4] = {1, 2};
    
    // Perform DFS
    cout << "DFS traversal:" << endl;
    vector<int> visitedDFS(landmarks.size(), 0);
    DFS(adjList, visitedDFS, 0); // Start DFS from the library (node 0)
    cout << endl;

    // Perform BFS
    cout << "BFS traversal:" << endl;
    vector<int> visitedBFS(landmarks.size(), false);
    BFS(adjList, visitedBFS, 0); // Start BFS from the library (node 0)
    cout << endl;

    return 0;
}
