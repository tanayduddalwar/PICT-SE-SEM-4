#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <string>
using namespace std;

class Graph {
public:
    void DFS(int node, vector<int>& visited, map<int, vector<int>>& adjList) {
        visited[node] = 1;
        cout << node << " ";
        for (auto it : adjList[node]) {
            if (!visited[it]) {
                DFS(it, visited, adjList);
            }
        }
    }

    void BFS(int node, vector<int>& visited,  map<int, vector<int>>& adjList) {
        queue<int> q;
        q.push(node);
        visited[node] = 1;
        while (!q.empty()) {
            int current_node = q.front();
            q.pop();
            cout << current_node << " ";
            for (auto it : adjList[current_node]) {
                if (!visited[it]) {
                    q.push(it);
                    visited[it] = 1;
                }
            }
        }
        cout << endl;
    }
};
int main() {
    map<string, int> landmarks = {
        {"library", 0},
        {"cafeteria", 1},
        {"gym", 2},
        {"park", 3},
        {"auditorium", 4}
    };

    map<int, vector<int>> adjList = {
        {0, {1, 2}},
        {1, {0, 3, 4}},
        {2, {0, 4}},
        {3, {1}},
        {4, {1, 2}}
    };

    Graph graph;
    vector<int> visited(adjList.size(), 0);
    cout << "DFS traversal:" << endl;
    graph.DFS(0, visited, adjList); // Start DFS from the library (node 0)
    cout << endl;

    cout << "BFS traversal:" << endl;
    fill(visited.begin(), visited.end(), 0); // Reset visited array for BFS
    graph.BFS(0, visited, adjList); // Start BFS from the library (node 0)
    cout << endl;

    return 0;
}
