#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, w;
};

int findParent(int v, vector<int>& parent) {
    if (v == parent[v]) return v;
    return parent[v] = findParent(parent[v], parent);
}

void unionSets(int a, int b, vector<int>& parent, vector<int>& rank) {
    a = findParent(a, parent);
    b = findParent(b, parent);

    if (rank[a] < rank[b])
        parent[a] = b;
    else if (rank[a] > rank[b])
        parent[b] = a;
    else {
        parent[b] = a;
        rank[a]++;
    }
}

int main() {
    int V = 4;
    vector<Edge> edges = {
        {0,1,10}, {0,2,6}, {0,3,5}, {1,3,15}, {2,3,4}
    };

    sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
        return a.w < b.w;
    });

    vector<int> parent(V), rank(V, 0);
    for (int i = 0; i < V; i++) parent[i] = i;

    cout << "Kruskal MST:\n";
    int cost = 0;

    for (auto &e : edges) {
        if (findParent(e.u, parent) != findParent(e.v, parent)) {
            cout << e.u << " -- " << e.v << "  (" << e.w << ")\n";
            cost += e.w;
            unionSets(e.u, e.v, parent, rank);
        }
    }

    cout << "Total Cost = " << cost << endl;
    return 0;
}
