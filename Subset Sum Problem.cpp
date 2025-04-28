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
