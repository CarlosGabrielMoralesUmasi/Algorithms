#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Función para encontrar un camino aumentante usando BFS
bool bfs(vector<vector<int>>& residualGraph, int source, int sink, vector<int>& parent) {
    int V = residualGraph.size();
    vector<bool> visited(V, false);
    queue<int> q;
    q.push(source);
    visited[source] = true;
    parent[source] = -1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v = 0; v < V; ++v) {
            if (!visited[v] && residualGraph[u][v] > 0) {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }

    return visited[sink];
}

// Función para encontrar el flujo máximo utilizando el algoritmo de Ford-Fulkerson
int fordFulkerson(vector<vector<int>>& graph, int source, int sink) {
    int V = graph.size();
    vector<vector<int>> residualGraph(V, vector<int>(V, 0));
    for (int u = 0; u < V; ++u) {
        for (int v = 0; v < V; ++v) {
            residualGraph[u][v] = graph[u][v];
        }
    }

    vector<int> parent(V);
    int maxFlow = 0;

    while (bfs(residualGraph, source, sink, parent)) {
        int pathFlow = INT_MAX;
        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            pathFlow = min(pathFlow, residualGraph[u][v]);
        }

        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            residualGraph[u][v] -= pathFlow;
            residualGraph[v][u] += pathFlow;
        }

        maxFlow += pathFlow;
    }

    return maxFlow;
}

// Ejemplo de uso
int main() {
    int V, source, sink;
    cout << "Ingrese el número de vértices: ";
    cin >> V;
    vector<vector<int>> graph(V, vector<int>(V, 0));

    cout << "Ingrese la fuente (source): ";
    cin >> source;

    cout << "Ingrese el sumidero (sink): ";
    cin >> sink;

    cout << "Ingrese las capacidades de las aristas:\n";
    for (int u = 0; u < V; ++u) {
        for (int v = 0; v < V; ++v) {
            cin >> graph[u][v];
        }
    }

    int maxFlow = fordFulkerson(graph, source, sink);
    cout << "El flujo máximo en la red es: " << maxFlow << endl;

    return 0;
}
