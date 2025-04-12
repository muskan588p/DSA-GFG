/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

class Solution {
  public:
  void solve(Node* root, int level, vector<int>& ans){
        //base case
        if(root==nullptr){
            return;
        }
        if(level ==  ans.size()){
            ans.push_back(root->data);
        }

        solve(root->left, level+1, ans);
        solve(root->right, level+1, ans);
    }
    vector<int> leftView(Node *root) {
        // code here
        vector<int> ans;

        solve(root, 0, ans);
        return ans;
    }
};

// Left View of Binary Tree

// You are given the root of a binary tree. Your task is to return the left view of the binary tree. The left view of a binary tree is the set of nodes visible when the tree is viewed from the left side.

// If the tree is empty, return an empty list.

// Examples :

// Input: root[] = [1, 2, 3, 4, 5, N, N]

// Output: [1, 2, 4]
// Explanation: From the left side of the tree, only the nodes 1, 2, and 4 are visible.
 
// Input: root[] = [1, 2, 3, N, N, 4, N, N, 5, N, N]

// Output: [1, 2, 4, 5]
// Explanation: From the left side of the tree, the nodes 1, 2, 4, and 5 are visible.

// Input: root[] = [N]
// Output: []
// Constraints:
// 0 <= number of nodes <= 106
// 0 <= node -> data <= 105

