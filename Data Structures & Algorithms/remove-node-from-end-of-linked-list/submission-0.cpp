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
    int len(ListNode* t){
        int count=0;
        while(t!=NULL){
            count++;
            t=t->next;
        }
        return count;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int total=len(head);
        int req=total-n;

        if(req==0)
            return head->next;
        ListNode *prev,*curr,*nextt,*temp=head;
        while(req){
            prev=temp;
            curr=temp->next;
            nextt=curr->next;
            temp=curr;
            req--;
        }
        prev->next=nextt;
        delete curr;
        return head;
    }
};
