// User function Template for C++
class Solution {
  public:
    int fib(int n, vector<int> &dp){
        if(n==1 || n==0){
            return n;
        }
        
        if(dp[n] != -1){
            return dp[n];
        }
        
        // return dp[n-1] + dp[n-2];   //recursion
        dp[n] = fib(n-1, dp) + fib(n-2, dp);
        return dp[n];
    }
    int nthFibonacci(int n) {
        // code here
        vector<int> dp(n+1);
        
        for(int i=0;i<=n;i++){        // <= because size n+1
            dp[i]=-1;
        }
        return fib(n, dp);
    }
};
