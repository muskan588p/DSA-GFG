#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> printAdjacency(int n, int m, vector<vector<int>> &edges) {
    vector<vector<int>> adj(n);

    // Build the adjacency list
    for (int i = 0; i < m; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Optional: sort for consistent order
    for (int i = 0; i < n; i++) {
        sort(adj[i].begin(), adj[i].end());
    }

    // Include node index at the beginning of each list
    vector<vector<int>> result;
    for (int i = 0; i < n; i++) {
        vector<int> row;
        row.push_back(i); // node index
        for (int neighbor : adj[i]) {
            row.push_back(neighbor);
        }
        result.push_back(row);
    }

    return result;
}
