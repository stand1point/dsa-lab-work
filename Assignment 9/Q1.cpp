#include <bits/stdc++.h>
using namespace std;

class Graph {
public:
    int V;
    vector<vector<pair<int,int>>> adj;  // {node, weight}

    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v, int w = 1, bool undirected = true) {
        adj[u].push_back({v, w});
        if (undirected) adj[v].push_back({u, w});
    }

    // ---------------------------
    // 1. Breadth First Search (BFS)
    // ---------------------------
    void BFS(int start) {
        vector<bool> visited(V, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        cout << "BFS Traversal: ";

        while (!q.empty()) {
            int u = q.front(); 
            q.pop();
            cout << u << " ";

            for (auto &p : adj[u]) {
                int v = p.first;
                if (!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
        cout << "\n";
    }

    // ---------------------------
    // 2. Depth First Search (DFS)
    // ---------------------------
    void DFSUtil(int u, vector<bool> &visited) {
        visited[u] = true;
        cout << u << " ";
        for (auto &p : adj[u]) {
            int v = p.first;
            if (!visited[v])
                DFSUtil(v, visited);
        }
    }

    void DFS(int start) {
        vector<bool> visited(V, false);
        cout << "DFS Traversal: ";
        DFSUtil(start, visited);
        cout << "\n";
    }

    // ------------------------------------
    // 3. Minimum Spanning Tree - KRUSKAL
    // ------------------------------------
    int findParent(int u, vector<int> &parent) {
        if (parent[u] == u) return u;
        return parent[u] = findParent(parent[u], parent);
    }

    void unionSet(int u, int v, vector<int> &parent, vector<int> &rank) {
        u = findParent(u, parent);
        v = findParent(v, parent);

        if (rank[u] < rank[v]) parent[u] = v;
        else if (rank[v] < rank[u]) parent[v] = u;
        else {
            parent[v] = u;
            rank[u]++;
        }
    }

    void KruskalMST() {
        vector< tuple<int,int,int> > edges;

        for (int u = 0; u < V; u++) {
            for (auto &p : adj[u]) {
                int v = p.first, w = p.second;
                if (u < v) edges.push_back({w, u, v});
            }
        }

        sort(edges.begin(), edges.end());

        vector<int> parent(V), rank(V, 0);
        for (int i = 0; i < V; i++) parent[i] = i;

        cout << "Kruskal MST Edges:\n";
        int totalWeight = 0;

        for (auto &e : edges) {
            int w, u, v;
            tie(w, u, v) = e;

            if (findParent(u, parent) != findParent(v, parent)) {
                cout << u << " - " << v << " : " << w << "\n";
                totalWeight += w;
                unionSet(u, v, parent, rank);
            }
        }

        cout << "Total MST Weight = " << totalWeight << "\n";
    }

    // ------------------------------------
    // 3. Minimum Spanning Tree - PRIM
    // ------------------------------------
    void PrimMST(int start = 0) {
        vector<int> key(V, INT_MAX);
        vector<bool> inMST(V, false);
        vector<int> parent(V, -1);

        key[start] = 0;

        for (int i = 0; i < V - 1; i++) {
            int u = -1;

            for (int v = 0; v < V; v++)
                if (!inMST[v] && (u == -1 || key[v] < key[u]))
                    u = v;

            inMST[u] = true;

            for (auto &p : adj[u]) {
                int v = p.first, w = p.second;

                if (!inMST[v] && w < key[v]) {
                    key[v] = w;
                    parent[v] = u;
                }
            }
        }

        cout << "Prim MST Edges:\n";
        int totalWeight = 0;

        for (int v = 1; v < V; v++) {
            cout << parent[v] << " - " << v << " : " << key[v] << "\n";
            totalWeight += key[v];
        }

        cout << "Total MST Weight = " << totalWeight << "\n";
    }

    // ------------------------------------
    // 4. Dijkstra Shortest Path Algorithm
    // ------------------------------------
    void Dijkstra(int start) {
        vector<int> dist(V, INT_MAX);
        dist[start] = 0;

        priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
        pq.push({0, start});

        while (!pq.empty()) {
            int u = pq.top().second;
            int d = pq.top().first;
            pq.pop();

            if (d > dist[u]) continue;

            for (auto &p : adj[u]) {
                int v = p.first, w = p.second;

                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }

        cout << "Dijkstra Shortest Distances:\n";
        for (int i = 0; i < V; i++)
            cout << start << " -> " << i << " = " << dist[i] << "\n";
    }
};

// ----------------------------------------------------
// Main Function
// ----------------------------------------------------
int main() {
    Graph g(6);

    g.addEdge(0, 1, 4);
    g.addEdge(0, 2, 2);
    g.addEdge(1, 2, 5);
    g.addEdge(1, 3, 10);
    g.addEdge(2, 4, 3);
    g.addEdge(4, 3, 4);
    g.addEdge(3, 5, 11);

    cout << "\n--- BFS ---\n";
    g.BFS(0);

    cout << "\n--- DFS ---\n";
    g.DFS(0);

    cout << "\n--- Kruskal MST ---\n";
    g.KruskalMST();

    cout << "\n--- Prim MST ---\n";
    g.PrimMST();

    cout << "\n--- Dijkstra ---\n";
    g.Dijkstra(0);

    return 0;
}
