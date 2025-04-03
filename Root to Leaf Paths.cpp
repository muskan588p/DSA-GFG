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

// Given a Binary Tree, you need to find all the possible paths from the root node to all the leaf nodes of the binary tree.

// Note: The paths should be returned such that paths from the left subtree of any node are listed first, followed by paths from the right subtree.

// Examples:

// Input: root[] = [1, 2, 3, 4, 5]
// ex-3
// Output: [[1, 2, 4], [1, 2, 5], [1, 3]] 
// Explanation: All possible paths: 1->2->4, 1->2->5 and 1->3
// Input: root[] = [1, 2, 3]
//        1
//     /     \
//    2       3
// Output: [[1, 2], [1, 3]] 
// Explanation: All possible paths: 1->2 and 1->3
// Input: root[] = [10, 20, 30, 40, 60]
//          10
//        /    \
//       20    30
//      /  \
//     40   60
// Output: [[10, 20, 40], [10, 20, 60], [10, 30]]
// Explanation: All possible paths: 10->20 ->40, 10->20->60 and 10->30
// Constraints:
// 1<=number of nodes<=104
// 1<=node->data<=104


