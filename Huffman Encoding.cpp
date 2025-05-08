// https://www.geeksforgeeks.org/problems/huffman-encoding3345/1

class Solution {
  public:
    class Node{
    public:
        int data;
        Node* left;
        Node* right;
          
        Node(int val){
            data=val;
            left=right=nullptr;
        }
    };
    class cmp{
        public:
        bool operator()(Node* a, Node*b){
         return a->data > b->data;
        }
    };
    
    void traverse(Node* root, vector<string> &ans, string temp){
        if(root==nullptr){
            return;
        }
        if(root->left==nullptr && root->right==nullptr){
            ans.push_back(temp);
            return;
        }
        traverse(root->left, ans, temp+"0");
        traverse(root->right, ans, temp+"1");
    }
    vector<string> huffmanCodes(string S, vector<int> f, int N) {
        // Code here
        priority_queue<Node*, vector<Node*>, cmp> pq;
        
        for(int i=0;i<N;i++){
            Node* temp=new Node(f[i]);
            pq.push(temp);
        }
        
        while(pq.size()>1){
            Node* left=pq.top();
            pq.pop();
            
            Node* right=pq.top();
            pq.pop();
            
            Node* newnode=new Node(left->data + right->data);
            newnode->left=left;
            newnode->right=right;
            
            pq.push(newnode);
        }
        Node* root=pq.top();
        
        vector<string> ans;
        string temp="";
        traverse(root, ans, temp);
        
        return ans;
        
    }
};

// Huffman Encoding

// Given a string S of distinct character of size N and their corresponding frequency f[ ] i.e. character S[i] has f[i] frequency. Your task is to build the Huffman tree print all the huffman codes in preorder traversal of the tree.
// Note: While merging if two nodes have the same value, then the node which occurs at first will be taken on the left of Binary Tree and the other one to the right, otherwise Node with less value will be taken on the left of the subtree and other one to the right.

// Example 1:

// S = "abcdef"
// f[] = {5, 9, 12, 13, 16, 45}
// Output: 
// 0 100 101 1100 1101 111
// Explanation:
// Steps to print codes from Huffman Tree
// HuffmanCodes will be:
// f : 0
// c : 100
// d : 101
// a : 1100
// b : 1101
// e : 111
// Hence printing them in the PreOrder of Binary 
// Tree.
// Your Task:
// You don't need to read or print anything. Your task is to complete the function huffmanCodes() which takes the given string S, frequency array f[ ] and number of characters N as input parameters and returns a vector of strings containing all huffman codes in order of preorder traversal of the tree.

// Expected Time complexity: O(N * LogN) 
// Expected Space complexity: O(N) 

// Constraints:
// 1 ≤ N ≤ 26


