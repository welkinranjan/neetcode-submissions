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

//even
// 21 3 12 54 76 4
// 21 4 3 76 12 54 

class Solution {
public:

    ListNode* rev(ListNode *t){
        ListNode* curr=t,*prev=NULL,*nextt;
        while(curr!=NULL){
            nextt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextt;
        }
        return prev;
    }

    int len(ListNode* t){
        int count=0;
        while(t!=NULL){
            count++;
            t=t->next;
        }
        return count;
    } 

    void reorderList(ListNode* head) {
        int n=len(head);
        ListNode* t=head;
        int half=n/2;
        while(half){
            t=t->next;
            half--;
        }
        ListNode* r_node=rev(t->next),*nextptr;
        t->next=NULL;
        t=head;
        while(r_node!=NULL){
            ListNode* t2=r_node->next,*t1=t->next;
            t->next=r_node;
            r_node->next=t1;
            t=t1;
            r_node=t2;
        }
    }
};
