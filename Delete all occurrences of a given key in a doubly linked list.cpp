/* a Node of the doubly linked list 
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x) { data = x; next = prev = NULL; }
}; */

class Solution {
  public:
    void deleteAllOccurOfX(struct Node** head, int x) {
        // Write your code here
        Node* temp=*head;
        while(temp!=nullptr){
            if(temp->data == x){
                Node* nextnode=temp->next;
                Node* prevnode=temp->prev;
                
                if(temp == *head){
                    *head=nextnode;
                }
                
                if(nextnode){
                    nextnode->prev=prevnode;
                }
                if(prevnode){
                    prevnode->next=nextnode;
                }
                
                free(temp);
                temp=nextnode;
            }
            else{
                temp=temp->next;
            }
        }
    }
};
