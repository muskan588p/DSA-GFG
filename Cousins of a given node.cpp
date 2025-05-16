class Solution {
  public:
    vector<int> printCousins(Node* root, Node* node_to_find) {
        if (root == nullptr || root == node_to_find)
            return {-1};

        queue<Node*> q;
        q.push(root);
        bool found = false;

        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                Node* temp = q.front();
                q.pop();

                // Check if current node is the parent of node_to_find
                if ((temp->left == node_to_find) || (temp->right == node_to_find)) {
                    found = true; // Don't enqueue children of this node
                } 
                else {
                    if (temp->left)
                        q.push(temp->left);
                    if (temp->right)
                        q.push(temp->right);
                }
            }
            // If parent found, break after this level
            if (found)
                break;
        }
        if (q.empty())
            return {-1};

        vector<int> ans;
        while (!q.empty()) {
            ans.push_back(q.front()->data);
            q.pop();
        }
        return ans;
    }
};
