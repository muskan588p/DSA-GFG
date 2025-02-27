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

// Given an increasing sorted rotated array arr of distinct integers. The array is right-rotated k times. Find the value of k.
// Let's suppose we have an array arr = [2, 4, 6, 9], so if we rotate it by 2 times so that it will look like this:
// After 1st Rotation : [9, 2, 4, 6]
// After 2nd Rotation : [6, 9, 2, 4]

// Examples:

// Input: arr = [5, 1, 2, 3, 4]
// Output: 1
// Explanation: The given array is 5 1 2 3 4. The original sorted array is 1 2 3 4 5. We can see that the array was rotated 1 times to the right.
// Input: arr = [1, 2, 3, 4, 5]
// Output: 0
// Explanation: The given array is not rotated.
// Expected Time Complexity: O(log(n))
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 <= n <=105
// 1 <= arri <= 107
