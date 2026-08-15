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
    
    ListNode* rev(ListNode* l){
        ListNode *curr=l,*prev=NULL,*nextt=l;
        while(curr!=NULL){
            nextt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextt;
        }
        return prev;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // l1=rev(l1);
        // l2=rev(l2);
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        int remainder = 0;
        while (l1 != NULL and l2 != NULL) {
            int sum = l1->val + l2->val + remainder;
            remainder = sum / 10;
            l1->val = sum % 10;
            curr->next = l1;
            curr = l1;
            l1 = l1->next;
            l2 = l2->next;
        }
        if (l1 == NULL) {
            while (l2 != NULL) {
                int sum = l2->val + remainder;
                remainder = sum / 10;
                l2->val = sum % 10;
                curr->next = l2;
                curr = l2;
                l2 = l2->next;
            }
        }
        if (l2 == NULL) {
            while (l1 != NULL) {
                int sum = l1->val + remainder;
                remainder = sum / 10;
                l1->val = sum % 10;
                curr->next = l1;
                curr=l1;
                l1 = l1->next;
            }
        }
        if (remainder) {
            curr->next = new ListNode(remainder);
        }
        return (dummy->next);
    }
};
