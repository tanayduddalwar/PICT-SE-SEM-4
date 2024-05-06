#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int minTotalCost(int numOffices, vector<pair<int,int>> connections[]) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,0});
    vector<int> visited(numOffices,0);
    int totalCost = 0;
    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        int cost = it.first;
        int office = it.second;
        if(visited[office]==1){
            continue;
        }
        totalCost += cost;
        visited[office] = 1;
        for(auto edge : connections[office]){
            int nextOffice = edge.first;
            int connectionCost = edge.second;
            if(!visited[nextOffice]){
                pq.push({connectionCost, nextOffice});
            }
        }
    }
    return totalCost;
}

void printConnections(int numOffices, vector<pair<int,int>> connections[]) {
    cout << "graph G {" << endl;
    for (int i = 0; i < numOffices; ++i) {
        for (auto& edge : connections[i]) {
            int to = edge.first;
            int cost = edge.second;
            cout << i << " -- " << to << " [label=\"" << cost << "\"];" << endl;
        }
    }
    cout << "}" << endl;
}

int main() {
    int numOffices; // Number of offices
    cout << "Enter the number of offices: ";
    cin >> numOffices;
    vector<pair<int,int>> connections[numOffices];

    // Taking input dynamically from the user
    int numConnections;
    cout << "Enter the number of connections: ";
    cin >> numConnections;
    cout << "Enter the connections in the format 'office1 office2 cost':" << endl;
    for (int i = 0; i < numConnections; ++i) {
        int office1, office2, cost;
        cin >> office1 >> office2 >> cost;
        connections[office1].push_back({office2, cost});
        connections[office2].push_back({office1, cost}); // Assuming bidirectional connections
    }

    printConnections(numOffices, connections);

    int minTotal = minTotalCost(numOffices, connections);
    cout << "Minimum total cost of connecting all offices: " << minTotal << endl;

    return 0;
}
