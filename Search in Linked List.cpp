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
