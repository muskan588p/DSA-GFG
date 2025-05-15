class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        //Step 1 Create adjacency list
        vector<vector<pair<int, int>>> adj(V);
        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w}); // undirected graph
        }

        //Step 2 Distance vector initialized to infinity
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;

        //Step 3 Min-heap {distance, node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, src});

        //Step 4 Dijkstra's logic
        while (!pq.empty()) {
            int d = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            for (auto &neighbor : adj[u]) {
                int v = neighbor.first;
                int wt = neighbor.second;
                if (dist[v] > d + wt) {
                    dist[v] = d + wt;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist;
    }
};
