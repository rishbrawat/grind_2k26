#include<vector>
#include<iostream>
using namespace std;

/*
    an adjacency matrix is a way of representing a graph a boolean matrix of 0s and 1s.
        - we use adjacency matrix to represent connection between vertices
        - initially the entire matrix is filled with 0s
        - if there is any edge between 0 and vertex 1, so we set mat[0][1] and mat[1][0] = 1

*/
vector<vector<int>> createGraph(int V, vector<vector<int>>& edges) {
    vector<vector<int>> mat(V, vector<int>(V,0));

    // adding each edge to the matrix
    for(auto& it: edges) {
        int u = it[0];
        int v = it[1];

        mat[u][v] = 1;
        // enable for undirected graph
        // mat[v][u] = 1;
    }
    return mat;
}

int main() {
    int V = 3;
    vector<vector<int>> edges = {
        {0,1},
        {0,2},
        {1,2},
    };

    vector<vector<int>> mat = createGraph(V, edges);

    cout << "adj matrix" << endl;
    for(int i = 0; i < V; ++i) {
        for(int j = 0; j < V; ++j) {
            cout << mat[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}