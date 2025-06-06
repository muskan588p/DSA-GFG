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
