#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> shortestPath(int V, vector<vector<int>>& edges, int start, int end) {
    vector<vector<int>> adj(V);
    for (auto &e : edges) {
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]); 
    }


    vector<int> parent(V, -1);
    vector<bool> visited(V, false);
    queue<int> q;

    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front(); q.pop();
        if (node == end) break;

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                parent[neighbor] = node;
                q.push(neighbor);
            }
        }
    }

    vector<int> path;
    if (!visited[end]) return path; 

    for (int at = end; at != -1; at = parent[at])
        path.push_back(at);

    reverse(path.begin(), path.end());
    return path;
}

int main() {
    int V = 5;
    vector<vector<int>> edges = {{0,1},{0,2},{1,3},{2,3},{3,4}};
    int start = 0, end = 4;

    vector<int> path = shortestPath(V, edges, start, end);

    if (path.empty()) {
        cout << "No path exists\n";
    } else {
        cout << "Shortest path: ";
        for (int node : path) cout << node << " ";
        cout << "\n";
    }
    return 0;
}
