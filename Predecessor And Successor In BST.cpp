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
