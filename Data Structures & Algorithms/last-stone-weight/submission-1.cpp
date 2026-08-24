class Solution {
public:

    int abs_(int a){
        return a<0?-a:a;
    }

    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxh;
        for(const auto& x:stones)
            maxh.push(x);
        while(maxh.size()>1){
            int f=maxh.top();
            maxh.pop();
            int s=maxh.top();
            maxh.pop();
            if(f==s)
                continue;
            maxh.push(abs_(f-s));
        }
        if(maxh.empty())
            return 0;
        return maxh.top();
    }
};
