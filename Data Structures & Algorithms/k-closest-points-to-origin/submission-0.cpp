class Solution {
   public:

    struct Node{
        public:
        double val;
        int f,s;
        Node(double val,int f,int s){
            this->val=val;
            this->f=f;
            this->s=s;
        }
    };

    struct cmp{
        bool operator()(const Node* a,const Node* b)const{
            //larger value higher priority
            return a->val<b->val;
        }
    };

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        priority_queue<Node*,vector<Node*>,cmp> pq;
        double val;
        for(auto& x:points){
            int f=x[0],s=x[1];
            val=sqrt(f*f+s*s);
            Node* p=new Node(val,f,s);
            pq.push(p);
            if(pq.size()>k)
                pq.pop();
        }
        while(!pq.empty()){
            vector<int> v;
            Node* t=pq.top();
            pq.pop();
            int fc=t->f,sc=t->s;
            v.push_back(fc);
            v.push_back(sc);
            ans.push_back(v);
        }
        return ans;
    }
};
