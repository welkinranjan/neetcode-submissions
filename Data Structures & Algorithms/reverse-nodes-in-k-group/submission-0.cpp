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
        ListNode *dummy=new ListNode(10);
        dummy->next=head;
        ListNode *prevgroup=dummy,*nextgroup;
        while(1){
            ListNode* p=prevgroup;
            for(int i=0;i<k;++i){
                p=p->next;
                if(p==NULL)
                    return dummy->next;
            }
            nextgroup=p->next;
            ListNode *prev=nextgroup;
            ListNode *curr=prevgroup->next;
            while(curr!=nextgroup){
                ListNode *temp=curr->next;
                curr->next=prev;
                prev=curr;
                curr=temp;
            }
            ListNode* tt=prevgroup->next;
            prevgroup->next=p;
            prevgroup=tt;
        }
        return dummy->next;
    }
};
