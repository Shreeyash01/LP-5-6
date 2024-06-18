#include <iostream>
#include <vector>
#include <omp.h>

using namespace std;

const int MAX = 100000;
vector<int> graph[MAX];
bool visited[MAX];

void dfs(int node) {
    if (!visited[node]) {
        visited[node] = true;
        cout << node << " ";

        // Create tasks for adjacent nodes
        #pragma omp task
        for (int i = 0; i < graph[node].size(); i++) {
            int adj_node = graph[node][i];
            dfs(adj_node);
        }
    }
}

int main() {
    int n, m, start_node;
    cout << "Enter no. of Nodes, no. of Edges, and Starting Node of the graph:\n";
    cin >> n >> m >> start_node;

    cout << "Enter pairs of nodes and edges:\n";
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        // u and v: Pair of edges
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    // Mark all nodes as unvisited
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }

    cout << "DFS traversal starting from node " << start_node << ":\n";

    // Explicitly parallelize the DFS traversal from the start node
    #pragma omp parallel
    #pragma omp single
    dfs(start_node);
    
    cout << endl;

    return 0;
}
