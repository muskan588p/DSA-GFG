// User function Template for C++
class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        int n = grid.size();
        int m = grid[0].size();
        
        if (grid[source.first][source.second] == 0 || 
            grid[destination.first][destination.second] == 0)
            return -1;
        
        if (source == destination)
            return 0;
        
        // Directions: up, right, down, left
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        
        queue<pair<int, pair<int, int>>> q;
        vector<vector<int>> visited(n, vector<int>(m, 0));
        
        q.push({0, {source.first, source.second}});
        visited[source.first][source.second] = 1;
        
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int dist = it.first;
            int row = it.second.first;
            int col = it.second.second;
            
            // Check destination
            if (row == destination.first && col == destination.second)
                return dist;
            
            for (int i = 0; i < 4; i++) {
                int newRow = row + dr[i];
                int newCol = col + dc[i];
                
                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m &&
                    !visited[newRow][newCol] && grid[newRow][newCol] == 1) {
                    visited[newRow][newCol] = 1;
                    q.push({dist + 1, {newRow, newCol}});
                }
            }
        }
        return -1;   //Destination not reachable
    }
};
