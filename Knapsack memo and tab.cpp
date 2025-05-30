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

// 0 - 1 Knapsack Problem
// Difficulty: MediumAccuracy: 31.76%Submissions: 482K+Points: 4
// Given n items, each with a specific weight and value, and a knapsack with a capacity of W, the task is to put the items in the knapsack such that the sum of weights of the items <= W and the sum of values associated with them is maximized. 

// Note: You can either place an item entirely in the bag or leave it out entirely. Also, each item is available in single quantity.

// Examples :

// Input: W = 4, val[] = [1, 2, 3], wt[] = [4, 5, 1] 
// Output: 3
// Explanation: Choose the last item, which weighs 1 unit and has a value of 3.
// Input: W = 3, val[] = [1, 2, 3], wt[] = [4, 5, 6] 
// Output: 0
// Explanation: Every item has a weight exceeding the knapsack's capacity (3).
// Input: W = 5, val[] = [10, 40, 30, 50], wt[] = [5, 4, 2, 3] 
// Output: 80
// Explanation: Choose the third item (value 30, weight 2) and the last item (value 50, weight 3) for a total value of 80.
// Constraints:
// 2 ≤ val.size() = wt.size() ≤ 103
// 1 ≤ W ≤ 103
// 1 ≤ val[i] ≤ 103
// 1 ≤ wt[i] ≤ 103
