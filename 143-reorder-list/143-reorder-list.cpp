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
    ListNode* findMidNode(ListNode* head){
        ListNode* slow = head, *fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* reverse(ListNode* head){
        ListNode* curr = head , *prev = NULL;
        ListNode* next;
        
        while(curr){
            next = curr->next;
            curr->next = prev;
            
            prev = curr;
            curr = next;
        }
        
        return prev;
    }
    void reorderList(ListNode* head) {
        if(!head || !head->next)
            return ;
        
        ListNode* mid = findMidNode(head);
        ListNode* second = reverse(mid);
        ListNode* first = head->next;
        bool flag = false;
        
        while(first != second){
            if(!flag){
                head->next = second;
                second = second->next;
                
            }else{
                head->next = first;
                first = first->next;
            }
            
            flag = !flag;
            head = head->next;
        }
       
    }
};