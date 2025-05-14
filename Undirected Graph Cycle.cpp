class Solution {
  public:
    bool dfs(vector<vector<int>> &adj, vector<bool> &vis, int node, int parent){
        vis[node]=true;
        
        for(int nei:adj[node]){
            if(!vis[nei]){
                if(dfs(adj, vis, nei, node)){
                    return true;
                }
            }
            else if(nei != parent){
                return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adj(V);
        
        int n=edges.size();
        for(int i=0;i<n;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> vis(V, false);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(adj, vis, i, -1)){       //start dfs from node i not 0
                    return true;
                }
            }
        }
        return false;
    }
};
