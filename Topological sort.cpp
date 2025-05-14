class Solution {
  public:
    void dfs(vector<vector<int>> &adj, vector<bool> &vis, int i, stack<int> &s){
        vis[i]=true;
        
        for(int nei:adj[i]){
            if(!vis[nei]){
                dfs(adj, vis, nei, s);
            }
        }
        //after all nei are visited - backtrack and push in stack
        s.push(i);
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> adj(V);
        
        int n=edges.size();
        for(int i=0;i<n;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            
            adj[u].push_back(v);
        }
        
        stack<int> s;
        vector<bool> vis(V, false);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(adj, vis, i, s);
            }
        }
        vector<int> ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};
