#include <iostream>
#include <vector>
using namespace std;

bool dfs(int node, int parent, vector<int> adj[], vector<int> &vis) {
    vis[node] = 1;
    for (int nei : adj[node]) {
        if (!vis[nei]) {
            if (dfs(nei, node, adj, vis)) return true;
        }
        else if (nei != parent) return true; 
    }
    return false;
}

bool hasCycle(int V, vector<vector<int>> &edges) {
    vector<int> adj[V];
    for (auto &e : edges) {
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]); 
    }
    vector<int> vis(V, 0);
    for (int i = 0; i < V; i++)
        if (!vis[i] && dfs(i, -1, adj, vis)) return true;
    return false;
}

int main() {
    int V = 5;
    vector<vector<int>> edges = {{0,1},{1,2},{2,3},{3,4},{4,0}};
    cout << (hasCycle(V, edges) ? "Cycle Detected" : "No Cycle");
    return 0;
}
