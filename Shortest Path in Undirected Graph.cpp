class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        // code here
        int v=adj.size();
        vector<int> dist(v, -1);   //this is the ans array also
        queue<int> q;
        
        dist[src]=0;
        q.push(src);
        
        while(!q.empty()){
            int node=q.front();
            q.pop();
            
            for(int nei : adj[node]){
                if(dist[nei] == -1){        //not visited ( == -1)
                    dist[nei] = 1 + dist[node];
                    q.push(nei);
                }
            }
        }
        return dist;
    }
};
