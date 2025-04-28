class Solution {
  public:
    bool solve(vector<int>& arr, int sum, int n, vector<vector<int>> &dp){
        if(sum==0){
            return true;
        }
        if(n==0){
            return false;
        }
        
        if(dp[n][sum] != -1){
            return dp[n][sum];
        }
        if(arr[n-1] <= sum){
            dp[n][sum]=solve(arr, sum-arr[n-1], n-1, dp) || solve(arr, sum, n-1, dp);
        }
        else{
            dp[n][sum]=solve(arr, sum, n-1, dp);
        }
        return dp[n][sum];
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n=arr.size();
        vector<vector<int>> dp(n+1, vector<int> (sum+1, -1));
        int ans=solve(arr, sum, n, dp);
        return ans;
    }
};
// class Solution {
//   public:
//     bool solve(vector<int>& arr, int sum, int n, vector<vector<int>> &dp){
//         if(sum==0){
//             return true;
//         }
//         if(n==0){
//             return false;
//         }
        
//         if(dp[n][sum] != -1){
//             return dp[n][sum];
//         }
//         if(arr[n-1] <= sum){
//             dp[n][sum]=solve(arr, sum-arr[n-1], n-1, dp) || solve(arr, sum, n-1, dp);
//         }
//         else{
//             dp[n][sum]=solve(arr, sum, n-1, dp);
//         }
//         return dp[n][sum];
//     }
//     bool isSubsetSum(vector<int>& arr, int sum) {
//         // code here
//         int n=arr.size();
//         vector<vector<int>> dp(n+1, vector<int> (sum+1, -1));
//         int ans=solve(arr, sum, n, dp);
//         return ans;
//     }
// };

//--------------------------------------------------------------------------------------------------------

// class Solution {
// public:
//     bool isSubsetSum(vector<int>& arr, int sum) {
//         int n = arr.size();
//         // dp[i][j] will be true if sum j is possible with the first i elements
//         vector<vector<bool>> dp(n+1, vector<bool>(sum+1, false));
        
//         // Base case: sum 0 is always possible (by choosing no elements)
//         for(int i = 0; i <= n; i++) {
//             dp[i][0] = true;
//         }
        
//         // Fill the DP table
//         for(int i = 1; i <= n; i++) {
//             for(int j = 1; j <= sum; j++) {
//                 if(arr[i-1] <= j) {
//                     // Include the current element or exclude it
//                     dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
//                 } else {
//                     // Exclude the current element
//                     dp[i][j] = dp[i-1][j];
//                 }
//             }
//         }
        
//         // The answer will be in dp[n][sum]
//         return dp[n][sum];
//     }
// };
