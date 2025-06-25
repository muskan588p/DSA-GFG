/*
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution {
  public:
    int findMax(Node *root) {
        if (root == NULL)
            return INT_MIN;  // Return smallest integer if tree is empty

        int leftMax = findMax(root->left);
        int rightMax = findMax(root->right);
        
        return max(root->data, max(leftMax, rightMax));
    }

    int findMin(Node *root) {
        if (root == NULL)
            return INT_MAX;  // Return largest integer if tree is empty

        int leftMin = findMin(root->left);
        int rightMin = findMin(root->right);

        return min(root->data, min(leftMin, rightMin));
    }
};

// Max and min element in Binary Tree
// Difficulty: EasyAccuracy: 60.57%Submissions: 37K+Points: 2
// Given a Binary Tree, find maximum and minimum elements in it.

// Example:

// Input: 
           
// Output: 11 1
// Explanation: The maximum and minimum element in this binary tree is 11 and 1 respectively.
// Input: 
//            6
//         / \
//        5   8
//       /
//      2
// Output: 8 2
// Explanation: The maximum and minimum element in this binary tree is 8 and 2 respectively.
// Constraints:
// 1 <= number of nodes <= 105
// 1 <= data of a node <= 105
