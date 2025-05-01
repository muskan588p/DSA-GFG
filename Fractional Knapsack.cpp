// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        vector<pair<double, pair<int, int>>> v;
        int n=val.size();
        
        for(int i=0;i<n;i++){
            double ratio= (double)val[i] / wt[i];
            v.push_back({ratio, {val[i], wt[i] }});
        }
        
        sort(v.rbegin(), v.rend());
        
        double totalval=0;
        for(int i=0;i<n;i++){
            int itemval=v[i].second.first;
            int itemwt=v[i].second.second;
            if(itemwt <= capacity){
                totalval += itemval;
                capacity -= itemwt;
            }
            else{
                totalval += v[i].first * capacity;     //v[i].first = ratio
                capacity=0;
            }
        }
        return totalval;
    }
};
