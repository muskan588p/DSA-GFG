class Solution {
  public:
    int solve(int W, vector<int> &val, vector<int> &wt, int n, vector<vector<int>> &dp){
        //base case
        if(n==0 || W==0){
            return 0;
        }
        
        if(dp[n][W] != -1){
            return dp[n][W];
        }
        int include=0;
        int exclude=0;
        
        if(wt[n-1] <= W){
            include=val[n-1] + solve(W-wt[n-1], val, wt, n-1, dp);
        }
        
        // Exclude choice must always exist, even when you can include the item.
        exclude=0+solve(W, val,wt, n-1, dp);
        
        dp[n][W]=max(include, exclude);
        return dp[n][W];
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n=val.size();
        vector<vector<int>> dp(n+1, vector<int>(W+1, -1));
        
        int ans=solve(W, val, wt, n, dp);   
        return ans;
    }
};
