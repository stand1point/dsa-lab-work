#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void BFS(int start, vector<vector<int>>& adj) {
    int n = adj.size();
    vector<bool> visited(n, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    cout << "BFS: ";

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << " ";

        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

int main() {
    vector<vector<int>> adj = {
        {1,2}, {0,3}, {0,4}, {1}, {2}
    };

    BFS(0, adj);
    return 0;
}
