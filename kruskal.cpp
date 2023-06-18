#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Estructura para representar una arista ponderada
struct Edge {
    int src, dest, weight;
};

// Estructura para representar un grafo conexo no dirigido
class Graph {
public:
    vector<Edge> edges; // Vector de aristas

    // Agrega una arista al grafo
    void addEdge(int src, int dest, int weight) {
        Edge edge;
        edge.src = src;
        edge.dest = dest;
        edge.weight = weight;
        edges.push_back(edge);
    }

    // Función de comparación utilizada para ordenar las aristas por peso
    static bool compare(const Edge& a, const Edge& b) {
        return a.weight < b.weight;
    }

    // Función para encontrar el subconjunto al que pertenece un elemento utilizando el algoritmo de búsqueda de la unión
    int findSubset(vector<int>& parent, int i) {
        if (parent[i] != i)
            parent[i] = findSubset(parent, parent[i]);
        return parent[i];
    }

    // Función para unir dos subconjuntos utilizando el algoritmo de búsqueda de la unión
    void unionSubset(vector<int>& parent, vector<int>& rank, int x, int y) {
        int xroot = findSubset(parent, x);
        int yroot = findSubset(parent, y);
        if (rank[xroot] < rank[yroot])
            parent[xroot] = yroot;
        else if (rank[xroot] > rank[yroot])
            parent[yroot] = xroot;
        else {
            parent[yroot] = xroot;
            rank[xroot]++;
        }
    }

    // Función para encontrar el árbol de expansión mínima utilizando el algoritmo de Kruskal
    void kruskalMST() {
        vector<Edge> result; // Vector para almacenar las aristas del árbol de expansión mínima
        int V = edges.size(); // Número de vértices en el grafo
        vector<int> parent(V); // Vector para almacenar el conjunto padre de cada vértice
        vector<int> rank(V, 0); // Vector para almacenar la clasificación de cada vértice

        // Inicializar los conjuntos padre para cada vértice
        for (int i = 0; i < V; i++)
            parent[i] = i;

        // Ordenar las aristas por peso en orden ascendente
        sort(edges.begin(), edges.end(), compare);

        int e = 0; // Índice de la próxima arista que se considerará

        // Seleccionar V-1 aristas con el menor peso para formar el árbol de expansión mínima
        while (result.size() < V - 1 && e < edges.size()) {
            Edge nextEdge = edges[e++];
            int x = findSubset(parent, nextEdge.src);
            int y = findSubset(parent, nextEdge.dest);

            // Si agregar esta arista no forma un ciclo, se incluye en el árbol de expansión mínima
            if (x != y) {
                result.push_back(nextEdge);
                unionSubset(parent, rank, x, y);
            }
        }

        // Imprimir las aristas del árbol de expansión mínima
        cout << "Aristas del árbol de expansión mínima:" << endl;
        for (int i = 0; i < result.size(); i++) {
            cout << result[i].src << " -- " << result[i].dest << "  Peso: " << result[i].weight << endl;
        }
    }
};

int main() {
    Graph graph;
    graph.addEdge(0, 1, 4);
    graph.addEdge(0, 7, 8);
    graph.addEdge(1, 2, 8);
    graph.addEdge(1, 7, 11);
    graph.addEdge(2, 3, 7);
    graph.addEdge(2, 8, 2);
    graph.addEdge(2, 5, 4);
    graph.addEdge(3, 4, 9);
    graph.addEdge(3, 5, 14);
    graph.addEdge(4, 5, 10);
    graph.addEdge(5, 6, 2);
    graph.addEdge(6, 7, 1);
    graph.addEdge(6, 8, 6);
    graph.addEdge(7, 8, 7);

    graph.kruskalMST();

    return 0;
}
