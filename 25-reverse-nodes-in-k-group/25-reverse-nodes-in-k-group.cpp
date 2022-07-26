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
    bool checkLessThanK(ListNode* head, int k){
        ListNode* curr = head;
        for(int i = 0;i<k;i++){
            if(!curr) return true;
            curr = curr->next;
        }
        return false;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        
        ListNode* before = dummy;
        ListNode* after = head;
        
        
        while(after){
            if(checkLessThanK(after,k))
                return dummy->next;
            
            ListNode* curr = after;
            ListNode* prev = before;
            
            for(int i = 0;i<k;i++){
                ListNode* next = curr->next;
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