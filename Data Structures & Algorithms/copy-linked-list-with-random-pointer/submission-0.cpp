/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*> umap;
        Node *t=head;
        while(t!=NULL){
            umap[t]=new Node(t->val);
            t=t->next;
        }
        t=head;
        while(t!=NULL){
            umap[t]->next=umap[t->next];
            umap[t]->random=umap[t->random];
            t=t->next;
        }
        return umap[head];
    }
};
