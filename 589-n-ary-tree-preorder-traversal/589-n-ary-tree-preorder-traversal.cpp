/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root) {
        if(!root) return {};
        
        stack<Node*> st;
        vector<int> ans;
        
        st.push(root);
        
        while(!st.empty()){
            Node* top = st.top();
            st.pop();
            
            ans.push_back(top->val);
            
            for(auto child = top->children.rbegin() ; child != top->children.rend() ; child++){
                if(*child){
                st.push(*child);
                                        
                }
            }
        }
        
        return ans;
    }
};