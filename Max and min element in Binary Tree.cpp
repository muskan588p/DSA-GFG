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
