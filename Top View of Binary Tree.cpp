/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution {
  public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root) {
        // code here
        vector<int> ans;
        map<int, int> mp;    //vertical dist, node
        
        if(root==nullptr){
            return ans;
        }
        queue<pair<Node* ,int>> q;  //root, vertical dist
        q.push({root, 0});
        
        while(!q.empty()){
            pair<Node*, int> temp= q.front();
            q.pop();
            
            Node* node= temp.first;
            int vd=temp.second;
            
            if(mp.find(vd) == mp.end()){
                mp[vd]=node->data;
            }
            
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
