#include<iostream>
#include<vector>
#include<queue>
using namespace std;

/*
    given a weighted undirected graph and source vertex src, we need to find the shortest path distance from the source vertex to all other nodes.

    the idea is to minimize distance using a distance array, it is initialized as infinite for all vertices and 0 for given source.

    - the priority queue data structure is used, it will always select the smallest current distance, ensuring that we explore the shortest path first and avoid processing of longer paths first.
*/

vector<int> dijkstra(vector<vector<pair<int, int>>>& adj, int src) {
    int V = adj.size();
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(V, INT_MAX);

    // set the source distance to 0
    dist[src] = 0;
    pq.emplace(0, src);

    // process the pqueue untill all nodes are done
    while(!pq.empty()) {
        auto top = pq.top();
        pq.pop();

        int d = top.first;
        int u = top.second;

        // if the distance is not the latest shortest one, skip it
        if(d > dist[u]) {
            continue;
        }

        // explore all neighbors of current vertex
        for(auto &p: adj[u]) {
            int v = p.first;
            int w = p.second;

            // if there is a new shortest path to v through u, update it
            if(dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.emplace(dist[v], v);
            }
        }
    }

    // return the shortest distances vector
    return dist;
}

