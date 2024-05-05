#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int spanningTree(int V, vector<pair<int,int>> adj[]) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,0});
    vector<int> vis(V,0);
    int sum=0;
    while(!pq.empty()){
        auto it=pq.top();
        pq.pop();
        int weight=it.first;
        int node=it.second;
        if(vis[node]==1){
            continue;
        }
        sum=sum+weight;
        vis[node]=1;
        for(auto it:adj[node]){
            int adjnode=it.first;
            int wei=it.second;
            if(!vis[adjnode]){
                pq.push({wei,adjnode});
            }
        }
    }
    return sum;
}

void printGraph(int V, vector<pair<int,int>> adj[]) {
    cout << "graph G {" << endl;
    for (int i = 0; i < V; ++i) {
        for (auto& edge : adj[i]) {
            int to = edge.first;
            int weight = edge.second;
            cout << i << " -- " << to << " [label=\"" << weight << "\"];" << endl;
        }
    }
    cout << "}" << endl;
}

int main() {
    int V; // Number of vertices
    cout << "Enter the number of vertices: ";
    cin >> V;
    vector<pair<int,int>> adj[V];

    // Taking input dynamically from the user
    int E;
    cout << "Enter the number of edges: ";
    cin >> E;
    cout << "Enter the edges in the format 'source destination weight':" << endl;
    for (int i = 0; i < E; ++i) {
        int source, destination, weight;
        cin >> source >> destination >> weight;
        adj[source].push_back({destination, weight});
    }

    printGraph(V, adj);

    int min_cost = spanningTree(V, adj);
    cout << "Minimum cost of spanning tree: " << min_cost << endl;

    return 0;
}
