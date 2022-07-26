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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        
        ListNode* before = dummy;
        ListNode* after = head;
        
        
        ListNode* prev = NULL;
        ListNode* curr = NULL;
        ListNode* next = NULL;
        
        while(after){
            ListNode* cursor = after;
            for(int i = 0;i<k;i++){
                if(!cursor) return dummy->next;
                cursor = cursor->next;
            }
            
            curr = after;
            prev = dummy;
            
            for(int i = 0;i<k;i++){
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            
            after->next = curr;
            before->next = prev;
            before = after;
            after = after->next;
        }
        return dummy->next;
    }
};