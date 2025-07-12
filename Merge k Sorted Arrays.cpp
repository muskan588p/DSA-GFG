class Solution {
public:
    vector<int> mergeKArrays(vector<vector<int>> arr, int k) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        
        for(int i=0;i<k;i++){         //row wise
            pq.push({arr[i][0], i, 0});
        }
        
        vector<int> ans;
        while(!pq.empty()){
            vector<int> top=pq.top();   //min val ele 
            pq.pop();
            
            int val=top[0];
            int row=top[1];         //array pos
            int col=top[2];         //ele pos
            
            ans.push_back(val);
            if(col+1 <  k){
                pq.push({arr[row][col+1], row, col+1});
            }
        }
        return ans;
    }
};

Merge k Sorted Arrays
Difficulty: MediumAccuracy: 67.25%Submissions: 117K+Points: 4Average Time: 45m
Given k sorted arrays arranged in the form of a matrix of size k * k. The task is to merge them into one sorted array. Return the merged sorted array ( as a pointer to the merged sorted arrays in cpp, as an ArrayList in java, and list in python).


Examples :

Input: k = 3, arr[][] = {{1,2,3},{4,5,6},{7,8,9}}
Output: 1 2 3 4 5 6 7 8 9
Explanation: Above test case has 3 sorted arrays of size 3, 3, 3 arr[][] = [[1, 2, 3],[4, 5, 6],[7, 8, 9]]. The merged list will be [1, 2, 3, 4, 5, 6, 7, 8, 9].
Input: k = 4, arr[][]={{1,2,3,4},{2,2,3,4},{5,5,6,6},{7,8,9,9}}
Output: 1 2 2 2 3 3 4 4 5 5 6 6 7 8 9 9 
Explanation: Above test case has 4 sorted arrays of size 4, 4, 4, 4 arr[][] = [[1, 2, 2, 2], [3, 3, 4, 4], [5, 5, 6, 6], [7, 8, 9, 9 ]]. The merged list will be [1, 2, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 8, 9, 9].
Expected Time Complexity: O(k2*Log(k))
Expected Auxiliary Space: O(k2)

Constraints:
1 <= k <= 100


