class Solution {
  public:
    // Function to find the length of a loop in the linked list.
    int countNodesinLoop(Node *head) {
        // Code here
        unordered_map<Node*, int> map;
        Node* temp=head;
        int timer=1;
        
        while(temp!=nullptr){
            if(map.find(temp) != map.end()){
                int value=map[temp];
                return timer-value;
            }
            map[temp]=timer;
            timer++;
            temp=temp->next;
        }
        return 0;
    }
};
