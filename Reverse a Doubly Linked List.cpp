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
