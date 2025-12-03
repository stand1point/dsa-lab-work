#include <iostream>
#include <vector>
using namespace std;

#define INF 999999

int main() {
    int V = 5;
    int graph[5][5] = {
        {0,2,0,6,0},
        {2,0,3,8,5},
        {0,3,0,0,7},
        {6,8,0,0,9},
        {0,5,7,9,0}
    };

    vector<int> key(V, INF);
    vector<bool> inMST(V, false);
    vector<int> parent(V, -1);

    key[0] = 0;

    for (int i = 0; i < V; i++) {
        int u = -1;

        for (int j = 0; j < V; j++)
            if (!inMST[j] && (u == -1 || key[j] < key[u]))
                u = j;

        inMST[u] = true;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !inMST[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    cout << "Prim's MST:\n";
    int cost = 0;
    for (int v = 1; v < V; v++) {
        cout << parent[v] << " -- " << v << " (" << graph[parent[v]][v] << ")\n";
        cost += graph[parent[v]][v];
    }
    cout << "Total Cost = " << cost << endl;

    return 0;
}
