class Solution {
  public:
  int findlength(Node* slow, Node* fast){
      int count=1;         //count is 1 initally because fastis starting from next node
      fast=fast->next;
      
      while(slow!=fast){
          count++;
          fast=fast->next;
      }
      return count;
  }
    // Function to find the length of a loop in the linked list.
    int countNodesinLoop(Node *head) {
        // Code here
        Node* slow=head;
        Node* fast=head;
        
        while(fast != nullptr && fast->next != nullptr){
            slow=slow->next;
            fast=fast->next->next;
            
            if(slow==fast){
                return findlength(slow,fast);
            }
        }
        return 0;
    }
};

