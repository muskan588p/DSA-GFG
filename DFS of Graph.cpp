class Solution {
  public:
    void solve(vector<vector<int>>& adj, int i, vector<bool> &vis, vector<int> &ans){
        vis[i]=true;
        ans.push_back(i);
        
        for(int nei:adj[i]){
            if(!vis[nei]){
                solve(adj, nei, vis, ans);     //pass nei for next
            }
        }
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int v=adj.size();
        vector<bool> vis(v, false);
        vector<int> ans;
        solve(adj, 0, vis, ans);
        
        return ans;
    }
};
