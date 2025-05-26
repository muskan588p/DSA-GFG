class Solution {
  public:
    // Function to find all pairs with given sum.
    vector<pair<int, int>> allPairs(int target, vector<int> &arr1, vector<int> &arr2) {
        // Code here
        int n=arr1.size();
        int m=arr2.size();
        
        vector<pair<int, int>> ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(arr1[i] + arr2[j] == target){
                    // cout<<arr1[i]<<" "<<arr2[j]<<", ";
                    ans.push_back({arr1[i], arr2[j]});
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
