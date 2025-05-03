// class Solution {
//   public:
//     int solve(vector<int>& arr, int sum, int n, vector<vector<int>> &dp){
//         if (n == 0) {
//             if (sum == 0) return 1;
//             else return 0;
//         }
        
//         if(dp[n][sum] != -1){
//             return dp[n][sum];
//         }
//         if(arr[n-1] <= sum){
//             dp[n][sum]=solve(arr, sum-arr[n-1], n-1, dp) + solve(arr, sum, n-1, dp);
//         }
//         else{
//             dp[n][sum]=solve(arr, sum, n-1, dp);
//         }
//         return dp[n][sum];
//     }
//     int perfectSum(vector<int>& arr, int target) {
//         // code here
//         int n=arr.size();
//         vector<vector<int>> dp(n+1, vector<int>(target+1, -1));
//         int ans=solve(arr, target, n, dp);
//         return ans;
//     }
// };

class Solution {
  public:
    int perfectSum(vector<int>& arr, int target) {
        int n = arr.size();
        int mod = 1e9 + 7;

        // dp[i][j] = number of subsets from first i elements that have sum j
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));

        // Base Case: There is one subset (empty subset) with sum 0 for all i
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= target; j++) {
                // Don't pick the current element
                dp[i][j] = dp[i - 1][j];

                // Pick the current element if it's <= j
                if (arr[i - 1] <= j) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - arr[i - 1]]) % mod;
                }
            }
        }

        return dp[n][target];
    }
};

// Perfect Sum Problem
// Difficulty: MediumAccuracy: 20.58%Submissions: 516K+Points: 4
// Given an array arr of non-negative integers and an integer target, the task is to count all subsets of the array whose sum is equal to the given target.

// Examples:

// Input: arr[] = [5, 2, 3, 10, 6, 8], target = 10
// Output: 3
// Explanation: The subsets {5, 2, 3}, {2, 8}, and {10} sum up to the target 10.
// Input: arr[] = [2, 5, 1, 4, 3], target = 10
// Output: 3
// Explanation: The subsets {2, 1, 4, 3}, {5, 1, 4}, and {2, 5, 3} sum up to the target 10.
// Input: arr[] = [5, 7, 8], target = 3
// Output: 0
// Explanation: There are no subsets of the array that sum up to the target 3.
// Input: arr[] = [35, 2, 8, 22], target = 0
// Output: 1
// Explanation: The empty subset is the only subset with a sum of 0.
// Constraints:
// 1 ≤ arr.size() ≤ 103
// 0 ≤ arr[i] ≤ 103
// 0 ≤ target ≤ 103


