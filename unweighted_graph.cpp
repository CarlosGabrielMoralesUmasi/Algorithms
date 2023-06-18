#include <iostream>
#include <vector>

using namespace std;

// Clase para representar el grafo
class Graph {
private:
    int V; // Número de vértices
    vector<vector<int>> adj; // Lista de adyacencia

public:
    // Constructor
    Graph(int vertices) {
        V = vertices;
        adj.resize(V);
    }

    // Agregar una arista al grafo
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); // Si el grafo no es dirigido, agregar esta línea
    }

    // Imprimir el grafo
    void printGraph() {
        for (int v = 0; v < V; ++v) {
            cout << "Adyacencias del vértice " << v << ": ";
            for (const auto& u : adj[v]) {
                cout << u << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    // Crear un grafo no ponderado
    Graph graph(5); // Grafo con 5 vértices

    // Agregar las aristas
    graph.addEdge(0, 1);
    graph.addEdge(0, 4);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);

    // Imprimir el grafo
    graph.printGraph();

    return 0;
}
