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
    ListNode* partition(ListNode* head, int x) {
        if(!head || !head->next) return head;
        
        ListNode* low = NULL , *high = NULL;
        ListNode* lowHead = NULL, *highHead = NULL;
        while(head){
            if(head->val < x){
                if(!lowHead){
                    lowHead = head;
                    low = lowHead;
                }else{
                    low->next = head;
                    low = low->next;
                }
            }else{
                if(!highHead){
                    highHead = head;
                    high = highHead;
                }else{
                    high->next = head;
                    high = high->next;
                }
            }
            head = head->next;
        }
        
        if(high)
            high->next = NULL;
        
        if(low)
            low->next = highHead;
        
        return lowHead ? lowHead : highHead;
       
    }
};