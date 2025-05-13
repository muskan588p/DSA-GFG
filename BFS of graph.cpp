class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
        int v=adj.size();
        queue<int> q;
        vector<bool> vis(v, false); 
        vector<int> ans;
        
        vis[0]=true;
        q.push(0);
        
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            ans.push_back(curr);
            
            for(int nei : adj[curr]){
                if( !vis[nei] ){
                    vis[nei]=true;
                    q.push(nei);
                }
            }
        }
        return ans;
    }
};
