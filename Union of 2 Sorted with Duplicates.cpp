class Solution {
  public:
    // a,b : the arrays
    // Function to return a list containing the union of the two arrays.
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        // Your code here
        // return vector with correct order of elements
        int n1=a.size();
        int n2=b.size();
        int i=0;
        int j=0;
        vector<int> uniarr;
        while(i<n1 && j<n2){
            if(a[i]<=b[j]){
                if(uniarr.size()==0 || uniarr.back() != a[i]){
                    uniarr.push_back(a[i]);
                }
                i++;
            }
            else{
                if(uniarr.size()==0 || uniarr.back() != b[j]){
                    uniarr.push_back(b[j]);
                }
                j++;
            }
        }
        while(i<n1){
            if(uniarr.size()==0 || uniarr.back() != a[i]){
                    uniarr.push_back(a[i]);
            }
            i++;
        }
        while(j<n2){
            if(uniarr.size()==0 || uniarr.back() != b[j]){
                    uniarr.push_back(b[j]);
                }
                j++;
        }
        return uniarr;
    }
};

// UNION OF 2 SORTED WITH DUPLICATES

// Given two sorted arrays a[] and b[], where each array may contain duplicate elements , the task is to return the elements in the union of the two arrays in sorted order.

// Union of two arrays can be defined as the set containing distinct common elements that are present in either of the arrays.
// Examples:

// Input: a[] = [1, 2, 3, 4, 5], b[] = [1, 2, 3, 6, 7]
// Output: 1 2 3 4 5 6 7
// Explanation: Distinct elements including both the arrays are: 1 2 3 4 5 6 7.
// Input: a[] = [2, 2, 3, 4, 5], b[] = [1, 1, 2, 3, 4]
// Output: 1 2 3 4 5
// Explanation: Distinct elements including both the arrays are: 1 2 3 4 5.
// Input: a[] = [1, 1, 1, 1, 1], b[] = [2, 2, 2, 2, 2]
// Output: 1 2
// Explanation: Distinct elements including both the arrays are: 1 2.
// Constraints:
// 1  <=  a.size(), b.size()  <=  105
// -109  <=  a[i] , b[i]  <=  109

