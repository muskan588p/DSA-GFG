class Solution {
  public:
    vector <int> bottomView(Node *root) {
        // Your Code Here
        vector<int> ans;
        map<int, int> mp;
        queue<pair<Node* , int>> q;
        
        if(root==nullptr){
            return ans;
        }
        
        q.push({root, 0});
        
        while(!q.empty()){
            pair<Node*, int> temp=q.front();
            q.pop();
            
            Node* node= temp.first;
            int vd=temp.second;
            
            mp[vd]= node->data;
            
            if(node->left){
                q.push({node->left, vd-1});
            }
            if(node->right){
                q.push({node->right, vd+1});
            }
        }
        for(auto i:mp){
            ans.push_back(i.second);
        }
        return ans;
    }
};
