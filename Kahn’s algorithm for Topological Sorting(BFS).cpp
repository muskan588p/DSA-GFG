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
// Topological sort
// Difficulty: MediumAccuracy: 56.52%Submissions: 301K+Points: 4Average Time: 15m
// Given a Directed Acyclic Graph (DAG) of V (0 to V-1) vertices and E edges represented as a 2D list of edges[][], where each entry edges[i] = [u, v] denotes a directed edge u -> v. Return the topological sort for the given graph.

// Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge u -> v, vertex u comes before v in the ordering.
// Note: As there are multiple Topological orders possible, you may return any of them. If your returned Topological sort is correct then the output will be true else false.

// Examples:

// Input: V = 4, E = 3, edges[][] = [[3, 0], [1, 0], [2, 0]]

// Output: true
// Explanation: The output true denotes that the order is valid. Few valid Topological orders for the given graph are:
// [3, 2, 1, 0]
// [1, 2, 3, 0]
// [2, 3, 1, 0]
// Input: V = 6, E = 6, edges[][] = [[1, 3], [2, 3], [4, 1], [4, 0], [5, 0], [5,2]]

// Output: true
// Explanation: The output true denotes that the order is valid. Few valid Topological orders for the graph are:
// [4, 5, 0, 1, 2, 3]
// [5, 2, 4, 0, 1, 3]
// Constraints:
// 2  ≤  V  ≤  5 x 103
// 1  ≤  E = edges.size()  ≤  min[105, (V * (V - 1)) / 2]

