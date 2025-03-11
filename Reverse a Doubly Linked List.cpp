/*
class DLLNode {
  public:
    int data;
    DLLNode *next;
    DLLNode *prev;

    DLLNode(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
*/
class Solution {
  public:
    // Function to reverse a doubly linked list
    DLLNode* reverseDLL(DLLNode* head) {
        // Your code here
        
        if(head==nullptr || head->next==nullptr){
            return head;
        }
        DLLNode* curr=head;
        DLLNode* prevnode=nullptr;
        while(curr!=nullptr){
            prevnode=curr->prev;
            curr->prev=curr->next;
            curr->next=prevnode;
            
            curr=curr->prev;
        }
        DLLNode* newhead=prevnode->prev;
        return newhead;
    }
};

// Reverse a Doubly Linked List

// Difficulty: EasyAccuracy: 70.38%Submissions: 170K+Points: 2Average Time: 15m
// Given a doubly linked list. Your task is to reverse the doubly linked list and return its head.

// Examples:

// Input: LinkedList: 3 <-> 4 <-> 5
// Output: 5 <-> 4 <-> 3

// Input: LinkedList: 75 <-> 122 <-> 59 <-> 196
// Output: 196 <-> 59 <-> 122 <-> 75

// Expected Time Complexity: O(n).
// Expected Auxiliary Space: O(1).

// Constraints:
// 1 <= number of nodes <= 106
// 0 <= node->data <= 104
