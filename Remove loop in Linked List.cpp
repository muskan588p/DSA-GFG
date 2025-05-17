/*
structure of linked list node:

struct Node
{
    int data;
    Node* next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

*/

class Solution {
  public:
    // Function to remove a loop in the linked list.
    void removeLoop(Node* head) {
        // code here
        if (head == nullptr || head->next == nullptr) return;
         
        Node* slow = head;
        Node* fast = head;
        Node* prev=nullptr;
        
        bool iscycle=false;
        
        while(fast!=nullptr && fast->next !=nullptr){
            slow=slow->next;
            fast=fast->next->next;
            
            if(slow==fast){
                iscycle=true;
                break;
            }
        }
        if(!iscycle){
            return;
        }
        slow=head;
        // Special case: Loop starts at head
        if (slow == fast) {
            while (fast->next != slow) {
                fast = fast->next;
            }
            fast->next = nullptr;
            return;
        }
        while(slow!=fast){
            slow=slow->next;
            prev=fast;
            fast=fast->next;
        }
        prev->next=nullptr;
    }
};
