class Solution {
  public:
    static bool cmp(pair<int, int> &a, pair<int, int> &b){
        return a.second > b.second;   //compare profit
    }
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        // code here
        int n=deadline.size();
        
        vector<pair<int, int>> v;
        for(int i=0;i<n;i++){
            v.push_back({deadline[i], profit[i]});
        }
        
        sort(v.begin(), v.end(), cmp);
        
        int maxdeadline=INT_MIN;
        for(int i=0;i<n;i++){
            maxdeadline=max(maxdeadline, deadline[i]);
        }
        
        vector<int> slot(maxdeadline+1, -1);   //initialize with -1
        int count=0;
        int maxprofit=0;
        
        for(int i=0;i<n;i++){
            int d=v[i].first;
            int p=v[i].second;
            
            for(int j=d; j>=1;j--){
                if(slot[j] == -1){
                    maxprofit += p;
                    slot[j] = i;
                    count++;
                    break;
                }
            }
        }
        return {count, maxprofit};
    }
};
