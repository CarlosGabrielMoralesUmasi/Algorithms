#include <iostream>
#include <vector>

using namespace std;

// Estructura para representar una arista del grafo
struct Edge {
    int src, dest, weight;
};

// Función para agregar una arista al grafo
void addEdge(vector<vector<Edge>>& graph, int src, int dest, int weight) {
    Edge edge;
    edge.src = src;
    edge.dest = dest;
    edge.weight = weight;
    graph[src].push_back(edge);
}

// Función para imprimir el grafo
void printGraph(const vector<vector<Edge>>& graph) {
    for (int i = 0; i < graph.size(); i++) {
        cout << "Nodo " << i << ": ";
        for (const Edge& edge : graph[i]) {
            cout << "(" << edge.dest << ", " << edge.weight << ") ";
        }
        cout << endl;
    }
}

int main() {
    int numNodes, numEdges;
    cout << "Ingrese el número de nodos del grafo: ";
    cin >> numNodes;
    cout << "Ingrese el número de aristas del grafo: ";
    cin >> numEdges;

    // Crear el grafo con un vector de vectores de aristas
    vector<vector<Edge>> graph(numNodes);

    cout << "Ingrese las aristas en el formato: nodo_fuente nodo_destino peso" << endl;
    for (int i = 0; i < numEdges; i++) {
        int src, dest, weight;
        cin >> src >> dest >> weight;
        addEdge(graph, src, dest, weight);
    }

    cout << endl << "Grafo creado:" << endl;
    printGraph(graph);

    return 0;
}
