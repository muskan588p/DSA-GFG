class Solution {
  public:
    int findMinDiff(vector<int>& a, int m) {
        int n=a.size();
        sort(a.begin(), a.end());
        int mindiff=INT_MAX;
        
        for(int i=0;i+m-1<n;i++){
            int diff=a[i+m-1] - a[i];
            mindiff= min(mindiff, diff);
        }
        return mindiff;
    }
};
