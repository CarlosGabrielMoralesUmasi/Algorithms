#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct Edge {
    int source;
    int destination;
    int weight;
};

void primMST(vector<vector<int>>& graph) {
    int V = graph.size();
    
    vector<bool> visited(V, false);
    vector<int> parent(V, -1);
    vector<int> key(V, INT_MAX);
    
    key[0] = 0; // Seleccionar el primer nodo como raíz
    
    for (int count = 0; count < V - 1; ++count) {
        int u = -1;
        
        // Encontrar el nodo no visitado con la menor clave
        for (int v = 0; v < V; ++v) {
            if (!visited[v] && (u == -1 || key[v] < key[u])) {
                u = v;
            }
        }
        
        visited[u] = true; // Marcar el nodo como visitado
        
        // Actualizar las claves de los nodos adyacentes no visitados
        for (int v = 0; v < V; ++v) {
            if (graph[u][v] != 0 && !visited[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }
    
    // Imprimir el árbol de expansión mínima
    cout << "Aristas del árbol de expansión mínima (Prim):" << endl;
    for (int i = 1; i < V; ++i) {
        cout << parent[i] << " - " << i << endl;
    }
}

int main() {
    int V;
    cout << "Ingrese el número de nodos: ";
    cin >> V;
    
    vector<vector<int>> graph(V, vector<int>(V, 0));
    
    cout << "Ingrese la matriz de adyacencia:" << endl;
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            cin >> graph[i][j];
        }
    }
    
    primMST(graph);
    
    return 0;
}
