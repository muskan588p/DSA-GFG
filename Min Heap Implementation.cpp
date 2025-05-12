// https://www.naukri.com/code360/problems/min-heap-implementation_5480527?leftPanelTabValue=PROBLEM

#include <bits/stdc++.h>
using namespace std;

class minHeap {
public:
    vector<int> arr;

    // Constructor to initialize with capacity
    minHeap(int capacity) {
        arr.reserve(capacity); 
    }

    // Default constructor
    minHeap() {}

    // Heapify function
    void heapify(int n, int i) {
        int smallest = i;  
        int lc = 2 * i + 1;
        int rc = 2 * i + 2;
        if (lc < n && arr[lc] < arr[smallest]) {
            smallest = lc;
        }
        if (rc < n && arr[rc] < arr[smallest]) {
            smallest = rc;
        }

        if (smallest != i) {
            swap(arr[i], arr[smallest]);
            heapify(n, smallest);
        }
    }

    int extractMinElement() {
        if (arr.empty()) {
            return -1;
        }

        if (arr.size() == 1) {
            int val = arr[0];
            arr.pop_back();
            return val;
        }

        swap(arr[0], arr[arr.size() - 1]);
        int minEle = arr.back();
        arr.pop_back();

        heapify(arr.size(), 0);
        return minEle;
    }

    void deleteElement(int ind) {
        if (ind >= arr.size()) return;

        arr[ind] = INT_MIN;

        while (ind > 0 && arr[(ind - 1) / 2] > arr[ind]) {
            swap(arr[ind], arr[(ind - 1) / 2]);
            ind = (ind - 1) / 2;
        }
        extractMinElement(); // Remove the root
    }

    void insert(int val) {
        arr.push_back(val);
        int idx = arr.size() - 1;
        while (idx > 0) {
            int parent = (idx - 1) / 2;
            if (arr[idx] < arr[parent]) {
                swap(arr[idx], arr[parent]);
                idx = parent;
            } else {
                break;
            }
        }
    }
};
