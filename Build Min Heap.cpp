#include <bits/stdc++.h> 
void minheapify(vector<int> &arr, int n, int i){
    int smallest=i;
    int lc=2*i+1;
    int rc=2*i+2;

    if(lc<n && arr[smallest] > arr[lc]){
        smallest=lc;
    }
    if(rc<n && arr[smallest] > arr[rc]){
        smallest=rc;
    }
    if(smallest != i){
        swap(arr[smallest], arr[i]);
        minheapify(arr, n, smallest);
    }
}
vector<int> buildMinHeap(vector<int> &arr)
{
    // Write your code here
    int n=arr.size();
    for (int i = (n / 2) - 1; i >= 0; i--) {
        minheapify(arr, n, i);
    }
    return arr;
}
