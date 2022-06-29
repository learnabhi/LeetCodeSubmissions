/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;
        
        ListNode* curr = head;
        while(curr){
            ListNode* prev = curr;
            while(curr->next && curr->val == curr->next->val){
                curr = curr->next;
            }
            prev->next = curr->next;
            prev = curr;
            curr = curr->next;
        }
        
        return head;
    }
};