#include<vector>
#include<iostream>
using namespace std;

vector<vector<int>> createGraph(int V, vector<vector<int>> edges) {
    vector<vector<int>> adj(V);

    // add the edges to the list
    for(auto &it: edges) {
        int u = it[0];
        int v = it[1];
        adj[u].push_back(v);

        // for undirected graph
        adj[v].push_back(u);
    }
    return adj;
}

int main() {
    int V = 3;
    vector<vector<int>> edges = {
        {0,1},
        {0,2},
        {1, 2}
    };

    vector<vector<int>> adj = createGraph(V, edges); 
    
    cout << "Adjacency List Representation:" << endl;
    for (int i = 0; i < V; i++) {
        
        // Print the vertex
        cout << i << ": "; 
        for (int j : adj[i]) {
            
            // Print its adjacent
            cout << j << " "; 
        }
        cout << endl; 
    }

    return 0;
}