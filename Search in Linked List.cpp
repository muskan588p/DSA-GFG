class Solution {
  public:
    // Function to count nodes of a linked list.
    bool searchKey(int n, Node* head, int key) {
        // Code here
        if(head==nullptr){
            return false;
        }
        Node* temp=head;
        while(temp != nullptr){       //to include last node also write temp!= null not temp->next!=null. this will go to second last node only
            if(temp->data == key){
                return true;
            }
            temp=temp->next;
        }
        return false;
    }
};
// Search in Linked List
// Difficulty: EasyAccuracy: 65.4%Submissions: 107K+Points: 2Average Time: 10m
// Given a linked list of n nodes and a key, the task is to check if the key is present in the linked list or not.

// Example:

// Input: n = 4, key = 3
// 1->2->3->4
// Output: true
// Explanation: 3 is present in Linked List, so the function returns true.
// Constraint:
// 1 <= n <= 105
// 1 <= key <= 105
