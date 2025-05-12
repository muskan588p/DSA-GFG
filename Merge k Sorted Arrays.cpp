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
