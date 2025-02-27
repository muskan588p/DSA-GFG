// User function template for C++
class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        int n=arr.size();
        int ans=INT_MAX;
        int idx=-1;
        int l=0;
        int h=n-1;
        while(l<=h){
            int mid=(l+h)/2;
            if(arr[l] <= arr[mid]){
                if(arr[l] < ans){
                    ans=arr[l];
                    idx=l;
                }
                // ans=min(ans,arr[l]); //instead of writing func write manually
                l=mid+1;
            }
            else{
                if(arr[mid] < ans){
                    ans=arr[mid];
                    idx=mid;
                }
                h=mid-1;
            }
        }
        return idx;
    }
};
