// class Solution {
//   public:
//     int solve(int W, vector<int> &val, vector<int> &wt, int n, vector<vector<int>> &dp){
//         // Base cases
//         if (n == 0 || W == 0) {
//             return 0;
//         }

//         if (dp[n][W] != -1) {
//             return dp[n][W];
//         }

//         dp[n][W] = solve(W, val, wt, n-1, dp); // not pick

//         if (wt[n-1] <= W) {
//             dp[n][W] = max(dp[n][W], val[n-1] + solve(W - wt[n-1], val, wt, n-1, dp)); // pick
//         }

//         return dp[n][W];
//     }

//     int knapsack(int W, vector<int> &val, vector<int> &wt) {
//         int n = val.size();
//         vector<vector<int>> dp(n+1, vector<int>(W+1, -1));
//         return solve(W, val, wt, n, dp);
//     }
// };

class Solution {
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = val.size();
        
        vector<vector<int>> dp(n+1, vector<int>(W+1, 0));
        
        for(int i = 1; i <= n; i++){
            for(int w = 0; w <= W; w++){
                
                dp[i][w] = dp[i-1][w]; // not pick case
                
                if(wt[i-1] <= w){ // pick case
                    dp[i][w] = max(dp[i][w], val[i-1] + dp[i-1][w - wt[i-1]]);
                }
            }
        }
        
        return dp[n][W];
    }
};
