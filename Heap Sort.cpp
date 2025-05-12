// The functions should be written in a way that array become sorted
// in increasing order when heapSort() is called.

class Solution {
  public:
    void heapify(vector<int>& arr, int n, int i){
        int largest=i;
        int lc=2*i+1;
        int rc=2*i+2;
        
        if(lc<n && arr[lc] > arr[largest]){
            largest=lc;
        }
        if(rc<n && arr[rc] > arr[largest]){
            largest=rc;
        }
        if(largest != i){
            swap(arr[largest], arr[i]);
            heapify(arr, n, largest);
        } 
    }
    // Function to sort an array using Heap Sort.
    void heapSort(vector<int>& arr) {
        // code here
        int n=arr.size();
        //build maxheap
        for(int i=n/2-1 ;i>=0;i--){
            heapify(arr, n, i);
        }
        int size=n;
        while(size > 1){
            swap(arr[0], arr[size-1]);
            size--;
            heapify(arr, size, 0);
        }
        // for(int i = n - 1; i >= 1; i--){
        //     swap(arr[0], arr[i]);     // Move max to end
        //     heapify(arr, i, 0);       // Heapify reduced heap
        // }
    }
};
