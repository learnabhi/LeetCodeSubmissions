/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB) return NULL;
        
        ListNode* currA = headA , *currB = headB;
        
        while(currA != currB){
            if(!currA)
                currA = headB;
            else 
                currA = currA->next;
            
            
            if(!currB)
                currB = headA;
            else 
                currB = currB->next;
            
        }
        
        return currA;
    }
};