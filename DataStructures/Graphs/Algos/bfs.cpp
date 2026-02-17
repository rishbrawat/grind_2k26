#include<vector>
#include<queue>
#include<iostream>
using namespace std;

vector<int> bfs(vector<vector<int>>& adj) {
    // for vertices in the bfs
    int V = adj.size();
    // an array for storing boolean values determined from visited nodes or not
    vector<bool> visited(V, false);
    // result array for the ouutput
    vector<int> res;

    // queue for keeping the track of next location
    queue<int> q;
    // source node
    int src = 0;
    visited[src] = true;
    q.push(src);


    while(!q.empty()) {
        int curr = q.front();
        q.pop();

        res.push_back(curr);

        // now visit all the remaining nodes in the graph
        for(int x: adj[curr]) {
            if(!visited[x]) {
                visited[x] = true;
                q.push(x);
            }
        }
    }

    return res;
}

int main() {
    vector<vector<int>> adj = {
        {1, 2},
        {2, 3},
        {4},
        {4},
        {}
    };

    vector<int> res = bfs(adj);
    for(int x: res) {
        cout << x << ' ';
    } cout << endl;

}