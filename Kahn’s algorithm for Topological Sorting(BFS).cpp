class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> adj(V);
        
        int n=edges.size();
        for(int i=0;i<n;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            
            adj[u].push_back(v);
        }
        
        vector<int> indegree(V, 0);  // Initialize all indegrees as 0

        for (int i = 0; i < V; i++) {
            for (int j = 0; j < adj[i].size(); j++) {
                int toNode = adj[i][j];     // Edge from i to toNode
                indegree[toNode]++;         // Increase indegree of the destination
            }
        }
        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        vector<int> result;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            result.push_back(node);
        
            // Decrease indegree of adjacent vertices as the
            // current node is in topological order
            for (auto it : adj[node]) {
                indegree[it]--;

                // If indegree becomes 0, push it to the queue
                if (indegree[it] == 0)
                    q.push(it);
            }
        }

        // Check for cycle
        if (result.size() != V) {
            cout << "Graph contains cycle!" << endl;
            return {};
        }

        return result;
        }
};
