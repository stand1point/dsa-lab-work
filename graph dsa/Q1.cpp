#include <iostream>
#include <vector>
using namespace std;

class Graph {
    int V;
    vector<vector<int>> adjMatrix;
    vector<vector<int>> adjList;

public:
    Graph(int vertices) {
        V = vertices;
        adjMatrix.assign(V, vector<int>(V, 0));
        adjList.assign(V, vector<int>());
    }

    void addEdge(int u, int v) {
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;     // Undirected

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    void displayMatrix() {
        cout << "\nAdjacency Matrix:\n";
        for (auto &row : adjMatrix) {
            for (int x : row) cout << x << " ";
            cout << endl;
        }
    }

    void displayList() {
        cout << "\nAdjacency List:\n";
        for (int i = 0; i < V; i++) {
            cout << i << ": ";
            for (int v : adjList[i])
                cout << v << " ";
            cout << endl;
        }
    }

    int degree(int v) {
        return adjList[v].size();
    }

    void adjacentVertices(int v) {
        cout << "Adjacent vertices of " << v << ": ";
        for (int x : adjList[v]) cout << x << " ";
        cout << endl;
    }

    int countEdges() {
        int edges = 0;
        for (int i = 0; i < V; i++)
            edges += adjList[i].size();
        return edges / 2; // undirected
    }
};

int main() {
    Graph g(5);

    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,3);
    g.addEdge(2,4);

    g.displayMatrix();
    g.displayList();

    cout << "\nDegree of vertex 0: " << g.degree(0);
    cout << "\nNumber of edges: " << g.countEdges() << endl;

    g.adjacentVertices(1);

    return 0;
}
