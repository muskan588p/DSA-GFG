// https://www.geeksforgeeks.org/problems/floor-in-bst/1

// Function to search a node in BST.
class Solution{

public:
    int floor(Node* root, int x) {
        // Code here
        int floor=-1;
        
        while(root!=nullptr){
            if(root->data == x){
                floor=root->data;
                return floor;
            }
            if(x > root->data){
                floor=root->data;
                root=root->right;
            }
            else{
                root=root->left;
            }
        }
        return floor;
    }
};
