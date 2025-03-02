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
