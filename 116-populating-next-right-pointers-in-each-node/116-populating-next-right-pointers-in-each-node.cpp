/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root || (!root->left && !root->right)) return root;
        
        Node* curr = root;
        
        while(curr){
            Node* level = curr;
            while(level){
                if(level->left){
                    level->left->next = level->right;
                    if(level->next)
                        level->right->next = level->next->left;
                }else{
                    break;
                }
                level = level->next;
            }
            curr = curr->left;
        }
        
        return root;
    }
};