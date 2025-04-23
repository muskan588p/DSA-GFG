class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    static bool cmp(pair<int, int> &a, pair<int, int> &b){
        return a.second < b.second;
    }
    int maxMeetings(vector<int>& start, vector<int>& end) {
        // Your code here
        int n=start.size();
        
        vector<pair<int, int>> v;
        for(int i=0;i<n;i++){
            v.push_back({start[i], end[i]});
        }
        
        sort(v.begin(), v.end(), cmp);
        
        int count=1;
        int prevend=v[0].second;
        
        for(int i=1;i<n;i++){                    //start i=1
            if(v[i].first > prevend){
                count++;
                prevend=v[i].second;
            }
        }
        return count;
    }
};
