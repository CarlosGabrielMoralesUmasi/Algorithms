#include <iostream>
#include <vector>

const int INF = 1e9; // Infinito

void floydWarshall(std::vector<std::vector<int>>& graph) {
    int n = graph.size();

    // Inicializar la matriz de distancias
    std::vector<std::vector<int>> dist(n, std::vector<int>(n, INF));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                dist[i][j] = 0;
            } else if (graph[i][j] != 0) {
                dist[i][j] = graph[i][j];
            }
        }
    }

    // Calcular las distancias mínimas
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    // Imprimir las distancias mínimas
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INF) {
                std::cout << "INF ";
            } else {
                std::cout << dist[i][j] << " ";
            }
        }
        std::cout << std::endl;
    }
}

int main() {
    int n, m;
    std::cin >> n >> m;

    // Crear la matriz de adyacencia del grafo
    std::vector<std::vector<int>> graph(n, std::vector<int>(n, 0));

    // Leer las aristas del grafo
    for (int i = 0; i < m; i++) {
        int u, v, w;
        std::cin >> u >> v >> w;
        graph[u][v] = w;
    }

    // Ejecutar el algoritmo de Floyd-Warshall
    floydWarshall(graph);

    return 0;
}
