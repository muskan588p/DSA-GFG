// https://www.geeksforgeeks.org/problems/longest-common-substring1452/1

class Solution {
  public:
    int longestCommonSubstr(string& s1, string& s2) {
        // your code here
        int n=s1.length();
        int m=s2.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        
        int maxlen=0;
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(s1[i]==s2[j]){
                    dp[i][j]= 1+ dp[i+1][j+1];
                    maxlen=max(maxlen, dp[i][j]);
                }
                else{
                    dp[i][j]=0;   //substr must be continous
                }
            }
        }
        return maxlen;
    }
};

// Longest Common Substring
// Difficulty: MediumAccuracy: 42.69%Submissions: 285K+Points: 4
// You are given two strings s1 and s2. Your task is to find the length of the longest common substring among the given strings.

// Examples:

// Input: s1 = "ABCDGH", s2 = "ACDGHR"
// Output: 4
// Explanation: The longest common substring is "CDGH" with a length of 4.
// Input: s1 = "abc", s2 = "acb"
// Output: 1
// Explanation: The longest common substrings are "a", "b", "c" all having length 1.
// Input: s1 = "YZ", s2 = "yz"
// Output: 0
// Constraints:
// 1 <= s1.size(), s2.size() <= 103
// Both strings may contain upper and lower case alphabets.


