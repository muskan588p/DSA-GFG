// https://www.naukri.com/code360/problems/build-min-heap_1171167?leftPanelTabValue=PROBLEM

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

//  Build Min Heap
// Moderate
// 80/80
// Average time to solve is 30m
// Contributed by
// 80 upvotes
// Asked in companies
// Problem statement
// You are given an array 'ARR' of integers having 'N' elements. Your task is to convert the input array into a min-Binary Heap.

// A min-Binary heap is a complete binary tree in which the value of each internal node is smaller than or equal to the values of the children of that node.

// Note :
// 1. Input array follows 0 - based indexing. 

// 2. After constructing the min-heap, the Left child of the 'i-th' node should be present at the (2*i + 1)-th index if it exists.

// 3. After constructing the min-heap, the Right child of the 'i-th' node should be present at the (2*i + 2)-th index if it exists.

// 4. Note that you do not need to create a tree, just update the array.
// Detailed explanation ( Input/output format, Notes, Images )
// Constraints :
// 1 <= T <= 10
// 1 <= N <= 10^4
// -10^9 <= ARR[i] <= 10^9

// Where 'ARR[i]' denotes the 'i-th' element of the array 'ARR'.

// Time Limit: 1 sec
// Sample Input 1 :
// 2
// 5
// 9 3 2 6 7 
// 4
// 1 3 2 4
// Sample Output 1 :
// 1
// 1
// Explanation For Sample Input 1 :
// For the first test case:
// One possible min-heap representation of the input array is the array [ 2, 3, 6, 7, 9 ]. Note that other arrays like [ 2, 6, 3, 9, 7 ], [ 2, 3, 6, 9, 7 ] also represent min-heap.

// For the second test case: 

// The input array is already a min-heap, so we do not need to modify it.
// Sample Input 2 :
// 2
// 5
// 1 3 5 4 6
// 3
// 8 9 0
// Sample Output 2 :
// 1 
// 1
// Explanation For Sample Input 2 :
// For the first test case:
// One possible min-heap representation of the input array is the array [ 1, 3, 5, 4, 6 ] which is the same as the input array. 

// For the second test case: 
// One possible min-heap representation of the input array is the array [ 0, 8, 9 ].
// C++ (g++ 5.4)
// 123456789101112131415161718192021222324252627
// #include <bits/stdc++.h> 
// void minheapify(vector<int> &arr, int n, int i){
//     int smallest=i;
//     int lc=2*i+1;
//     int rc=2*i+2;

//     if(lc<n && arr[smallest] > arr[lc]){
//         smallest=lc;
//     }
//     if(rc<n && arr[smallest] > arr[rc]){


