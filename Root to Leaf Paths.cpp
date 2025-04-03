class Solution {
  public:
    void solve(Node* root, vector<vector<int>>& ans, vector<int>& curr){
        if(root==nullptr){
            return;
        }
        
        curr.push_back(root->data);
        if(root->left==nullptr && root->right==nullptr){    //if lead node 1 path is found
            ans.push_back(curr);
        }
        solve(root->left, ans, curr);
        solve(root->right, ans, curr);
        
        // Backtrack 
        curr.pop_back();
        
    }
    vector<vector<int>> Paths(Node* root) {
        // code here
        vector<vector<int>> ans;
        vector<int> curr;
        solve(root, ans, curr);
        
        return ans;
        
    }
};
