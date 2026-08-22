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

    ListNode* combine(ListNode* a,ListNode* b){
        ListNode *dummy=new ListNode(5);
        ListNode* t=dummy;
        while(a!=NULL and b!=NULL){
            if(a->val<=b->val){
                t->next=a;
                t=a;
                a=a->next;
            }
            else{
                t->next=b;
                t=b;
                b=b->next;
            }
        }
        if(a!=NULL)
            t->next=a;
        if(b!=NULL)
            t->next=b;
        return dummy->next;
    }

    ListNode* mergesort(vector<ListNode*> &list,int l,int r){
        //base case
        if(l>=r)
            return list[l];
        int mid=l+(r-l)/2;
        ListNode* left= mergesort(list,l,mid);
        ListNode* right= mergesort(list,mid+1,r);
        return combine(left,right);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0)
            return NULL;
        return mergesort(lists,0,lists.size()-1);
    }
};
