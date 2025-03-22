*
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    void traverseleft(Node *root, vector<int>& ans){
        if(root==nullptr || (root->left==nullptr && root->right==nullptr)){
            return;
        }
        ans.push_back(root->data);
        //check if left exists or right
        if(root->left){
            traverseleft(root->left, ans);
        }
        else{
            traverseleft(root->right, ans);
        }
    }
    void traverseleaf(Node *root, vector<int>& ans){
        if(root==nullptr){
            return;
        }
        
        if(root->left==nullptr && root->right==nullptr){
            ans.push_back(root->data);
        }
        traverseleaf(root->left, ans);
        traverseleaf(root->right, ans);
    }
    void traverseright(Node* root, vector<int>& ans){
        if(root==nullptr || (root->left==nullptr && root->right==nullptr)){
            return;
        }
        //check if left exists or right
        if(root->right){
            traverseright(root->right, ans);
        }
        else{
            traverseright(root->left, ans);
        }
        
        ans.push_back(root->data);
    }
    vector<int> boundaryTraversal(Node *root) {
        // code here
        vector<int> ans;
        if (root == nullptr) {
            return ans;
        }
         ans.push_back(root->data); //ADD THE ROOT DATA FIRST
         
        //left boundary
        traverseleft(root->left, ans);
        
        //leaf nodes
        //left and right subtree
        traverseleaf(root->left, ans);
        traverseleaf(root->right, ans);
        
        //right boundary reverse
        traverseright(root->right,ans);
        
        return ans;
    }
};
