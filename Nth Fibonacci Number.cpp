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
// Nth Fibonacci Number
// Difficulty: EasyAccuracy: 22.3%Submissions: 355K+Points: 2
// Given a non-negative integer n, your task is to find the nth Fibonacci number.

// The Fibonacci sequence is a sequence where the next term is the sum of the previous two terms. The first two terms of the Fibonacci sequence are 0 followed by 1. The Fibonacci sequence: 0, 1, 1, 2, 3, 5, 8, 13, 21

// The Fibonacci sequence is defined as follows:

// F(0) = 0
// F(1) = 1
// F(n) = F(n - 1) + F(n - 2) for n > 1
// Examples :

// Input: n = 5
// Output: 5
// Explanation: The 5th Fibonacci number is 5.
// Input: n = 0
// Output: 0 
// Explanation: The 0th Fibonacci number is 0.
// Input: n = 1
// Output: 1
// Explanation: The 1st Fibonacci number is 1.
// Constraints:
// 0 ≤ n ≤ 30

