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
        if(!root) return NULL;
        
        Node* currLevelNode = root;
        Node* headNextLevel = NULL , *prevNextLevel = NULL;
        
        while(currLevelNode){
            while(currLevelNode){
                // left child
                if(currLevelNode->left){
                    if(prevNextLevel)
                        prevNextLevel->next = currLevelNode->left;
                    else
                        headNextLevel = currLevelNode->left;
                
                    prevNextLevel = currLevelNode->left;
                }
                // right child
                if(currLevelNode->right){
                    if(prevNextLevel)
                        prevNextLevel->next = currLevelNode->right;
                    else
                        headNextLevel = currLevelNode->right;
                    
                    prevNextLevel = currLevelNode->right;
                }
                
                currLevelNode = currLevelNode->next;
            }
            currLevelNode = headNextLevel;
            headNextLevel = NULL ;
            prevNextLevel = NULL;
        }
        
        return root;
    }
};