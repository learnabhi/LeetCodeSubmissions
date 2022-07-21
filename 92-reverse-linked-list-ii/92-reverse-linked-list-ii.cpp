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
    pair<ListNode*,ListNode*> reverse(ListNode* head, int n){
        ListNode* curr = head, *prev = NULL;
        ListNode* next;
        
        while(curr && n--){
            next = curr->next;
            curr->next = prev;
            
            prev = curr;
            curr = next;
        }
        return {prev,curr};
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head || !head->next || right == left) return head;
        
        ListNode* curr = head, *prev = NULL;
        int len = right - left + 1;
        while(--left){
            prev = curr;
            curr = curr->next;
        }
        
        auto res = reverse(curr , len);
        
        if(prev)
            prev->next = res.first;
        else
            head = res.first;
        
        
        if(curr)
            curr->next = res.second;
        
        
        return head;
    }
};