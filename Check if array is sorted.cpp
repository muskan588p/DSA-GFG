// User function template for C++

class Solution {
  public:
    bool arraySortedOrNot(vector<int>& arr) {
        // code here
        int n=arr.size();
        for(int i=1;i<n;i++){
            if(arr[i] < arr[i-1]){
                return false;    //thus check false condition
            }
        }
        return true;
    }
};
//     If at least one pair of elements has arr[i] > arr[i - 1], return true.

// But this is not enough to prove the array is fully sorted.
//  code incorrectly assumes the array is sorted just because there's one increasing pair, but all pairs must be non-decreasing.
