class Solution {
  public:
    bool dfs(vector<vector<int>> &adj, vector<bool> &vis, vector<bool> &dfsvis, int i){
        vis[i]=true;
        dfsvis[i]=true;
        
        for(int nei:adj[i]){
            if(!vis[nei]){
                if(dfs(adj, vis, dfsvis, nei)){
                    return true;
                }
            }
            else if(vis[nei] == true && dfsvis[nei]==true){
                return true;
            }
        }
        dfsvis[i]=false;    //backtrack
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>> adj(V);
        
        int n=edges.size();
        for(int i=0;i<n;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            
            adj[u].push_back(v);
        }
        vector<bool> vis(V, false);
        vector<bool> dfsvis(V, false);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(adj, vis, dfsvis, i)){
                    return true;
                }
            }
        }
        return false;
    }
};
