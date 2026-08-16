class LRUCache {
public:

    struct node{
        node *next,*prev;
        int key,val;

        node(int k,int v){
            key=k;
            val=v;
            next=prev=NULL;
        }
    };

    int limit;
    node *head;
    node *tail;
    LRUCache(int capacity) {
        limit=capacity;
        head=new node(-1,-1);
        tail=new node(-1,-1);
        head->next=tail;
        tail->prev=head;
    }
    
    unordered_map<int,node*> umap;

    void delnode(node* t){
        node *prevnode=t->prev;
        node *nextnode=t->next;
        prevnode->next=nextnode;
        nextnode->prev=prevnode;
        delete t;
    }

    void insertnode(node* t){
        node *nextnode=head->next;
        head->next=t;
        t->next=nextnode;
        t->prev=head;
        nextnode->prev=t;
    }

    int get(int key) {
        if(umap.find(key)==umap.end())
            return -1;
        node* oldnode=umap[key];
        int ans=oldnode->val;
        node *t=new node(key,ans);
        umap.erase(key);
        delnode(oldnode);
        insertnode(t);
        umap[key]=t;
        return ans;
    }
    
    void put(int key, int value) {
        if(umap.find(key)!=umap.end()){
            delnode(umap[key]);
            umap.erase(key);
        }
        if(limit==umap.size()){
            node* t=tail->prev;
            int k=t->key;
            delnode(t);
            umap.erase(k);
        }
        node *newnode=new node(key,value);
        umap[key]=newnode;
        insertnode(newnode);
    }
};
