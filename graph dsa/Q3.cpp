#include <iostream>
#include <vector>
using namespace std;

void DFSUtil(int u, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[u] = true;
    cout << u << " ";

    for (int v : adj[u]) {
        if (!visited[v])
            DFSUtil(v, adj, visited);
    }
}

void DFS(int start, vector<vector<int>>& adj) {
    vector<bool> visited(adj.size(), false);
    cout << "DFS: ";
    DFSUtil(start, adj, visited);
}

int main() {
    vector<vector<int>> adj = {
        {1,2}, {0,3}, {0,4}, {1}, {2}
    };

    DFS(0, adj);
    return 0;
}
