#include <iostream>
#include <vector>
using namespace std;

#define INF 999999

int main() {
    int V = 5;
    int graph[5][5] = {
        {0, 10, 0, 0, 5},
        {0, 0, 1, 0, 2},
        {0, 0, 0, 4, 0},
        {7, 0, 6, 0, 0},
        {0, 3, 9, 2, 0}
    };

    vector<int> dist(V, INF);
    vector<bool> visited(V, false);

    dist[0] = 0;

    for (int i = 0; i < V; i++) {
        int u = -1;

        // Pick smallest unvisited distance
        for (int j = 0; j < V; j++)
            if (!visited[j] && (u == -1 || dist[j] < dist[u]))
                u = j;

        visited[u] = true;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
        }
    }

    cout << "Dijkstra Shortest Paths from source 0:\n";
    for (int i = 0; i < V; i++)
        cout << "0 → " << i << " = " << dist[i] << endl;

    return 0;
}
