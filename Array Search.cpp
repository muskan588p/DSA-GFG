class Solution {
  public:
    // Function to search x in arr
    // arr: input array
    // X: element to be searched for
    int search(vector<int>& arr, int x) {
        // Your code here
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            if (arr[i] == x)
                return i; // Return the index of first occurrence
        }
        return -1; // Return -1 if element is not found
    
    }
};
