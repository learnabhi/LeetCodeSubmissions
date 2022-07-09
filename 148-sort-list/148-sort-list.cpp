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
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        
        ListNode* slow = head , *fast = head->next;
        
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        fast = slow->next;
        slow->next = NULL;
        
        return merge(sortList(head) , sortList(fast));
    }
    
    ListNode* merge(ListNode* head1 , ListNode* head2){
        if(!head1 && !head2) return NULL;
        else if(!head1) return head2;
        else if(!head2) return head1;
        
        ListNode* head = NULL;
        if(head1->val <= head2->val){
            head = head1;
            head1 = head1->next;
        }else{
            head = head2;
            head2 = head2->next;
        }
        
        ListNode* curr = head;
        while(head1 && head2){
            if(head1->val <= head2->val){
                curr->next = head1;
                head1 = head1->next;
            }else{
                curr->next = head2;
                head2 = head2->next;
            }
            curr = curr->next;
        }
        
        if(head1) curr->next = head1;
        if(head2) curr->next = head2;
        
        return head;
    }
};