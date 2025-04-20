// https://www.naukri.com/code360/problems/_893049?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0

/*************************************************************

    Following is the Binary Tree node structure
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };

*************************************************************/

pair<int, int> predecessorSuccessor(TreeNode *root, int key){
    TreeNode* temp=root;
    int pre=-1;
    int suc=-1;

    //find key
    while(temp != nullptr && temp->data != key){
        if(key < temp->data){
            suc=temp->data;
            temp=temp->left;
        }
        else{  //ley > root->val
            pre=temp->data;
            temp=temp->right;
        }
    }
    if(temp != nullptr){
        //pred
        TreeNode* leftree = temp->left;
        while(leftree != nullptr){  //exists
            pre=leftree->data;
            leftree=leftree->right;    //largest val that is smaller than key
        }

        //succ
        TreeNode* rightree=temp->right;
        while(rightree != nullptr){
            suc= rightree->data;
            rightree=rightree->left;     //smallest val that is greater then key
        }
    }    
    pair<int, int> ans=make_pair(pre, suc);
    return ans;

    //return {pre, suc};

// Predecessor And Successor In BST
// You have been given a binary search tree of integers with ‘N’ nodes. You are also given 'KEY' which represents data of a node of this tree.

// Your task is to return the predecessor and successor of the given node in the BST.



// Note:
// 1. The predecessor of a node in BST is that node that will be visited just before the given node in the inorder traversal of the tree. If the given node is visited first in the inorder traversal, then its predecessor is NULL.

// 2. The successor of a node in BST is that node that will be visited immediately after the given node in the inorder traversal of the tree. If the given node is visited last in the inorder traversal, then its successor is NULL.

// 3. The node for which the predecessor and successor will not always be present. If not present, you can hypothetically assume it's position (Given that it is a BST) and accordingly find out the predecessor and successor.

// 4. A binary search tree (BST) is a binary tree data structure which has the following properties.
//      • The left subtree of a node contains only nodes with data less than the node’s data.
//      • The right subtree of a node contains only nodes with data greater than the node’s data.
//      • Both the left and right subtrees must also be binary search trees.


// Detailed explanation ( Input/output format, Notes, Images )
// Sample Input 1:
// 15 10 20 8 12 16 25 -1 -1 -1 -1 -1 -1 -1 -1
// 10
// Sample output 1:
// 8 12
// Explanation of Sample output 1:
// The tree can be represented as follows:

// The inorder traversal of this tree will be 8 10 12 15 16 20 25.

// Since the node with data 8 is on the immediate left of the node with data 10 in the inorder traversal, the node with data 8 is the predecessor.

// Since the node with data 12 is on the immediate right of the node with data 10 in the inorder traversal, the node with data 12 is the successor.
// Sample Input 2:
// 10 5 -1 -1 -1
// 5
// Sample output 2:
// -1 10
// Constraint :
// 1 <= N <= 10^4
// 1 <= data <= 10^7

// Time Limit: 1 sec
// C++ (g++ 5.4)
// 1234567891011121314151617181920212223242526
// /*************************************************************

//     Following is the Binary Tree node structure
//     class TreeNode
//     {
//     public:
//         int data;
//         TreeNode *left, *right;
//         TreeNode() : data(0), left(NULL), right(NULL) {}
//         TreeNode(int x) : data(x), left(NULL), right(NULL) {}


