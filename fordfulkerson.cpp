#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm> 
using namespace std;

bool bfs(vector<vector<int>> &rGraph, int s, int t, vector<int> &parent, int V) {
    vector<bool> visited(V, false);
    queue<int> q;

    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while (!q.empty()) {
        int u = q.front(); q.pop();

        for (int v = 0; v < V; v++) {
            if (!visited[v] && rGraph[u][v] > 0) {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
    return visited[t];
}

int fordFulkerson(vector<vector<int>> &graph, int s, int t, int V) {
    vector<vector<int>> rGraph = graph;
    vector<int> parent(V);
    int max_flow = 0;

    while (bfs(rGraph, s, t, parent, V)) {
        int path_flow = INT_MAX;

        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }

        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }

        max_flow += path_flow;
    }
    return max_flow;
}

int main() {
    cout<<"Name: Hargun Kaur Kohli"<<endl<<"Registeration Number: 24BCE2198"<<endl;
    int V;
    cout << "Enter number of vertices: ";
    cin >> V;

    vector<vector<int>> graph(V, vector<int>(V));

    cout << "Enter adjacency matrix:\n";
    for(int i=0;i<V;i++)
        for(int j=0;j<V;j++)
            cin >> graph[i][j];

    int s, t;
    cout << "Enter source: ";
    cin >> s;
    cout << "Enter sink: ";
    cin >> t;
    if (s < 0 || t < 0 || s >= V || t >= V || s == t) {
        cout << "Invalid case: incorrect source/sink\n";
        return 0;
    }
    if (V == 2) {
        cout << "Maximum Flow = " << graph[0][1] << endl;
        return 0;
    }

    int maxFlow = fordFulkerson(graph, s, t, V);

    if (maxFlow == 0)
        cout << "Maximum Flow = 0 (No path exists)\n";
    else
        cout << "Maximum Flow = " << maxFlow << endl;

    return 0;
}