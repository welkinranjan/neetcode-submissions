class Solution {
public:
    using pii=pair<int,int>;
    int leastInterval(vector<char>& tasks, int n) {
        //queue+max heap+frequency
        vector<int> freq(26,0);
        for(const auto& it:tasks)
            freq[it-'A']++;
        priority_queue<int> pq;
        for(auto& it:freq){
            if(it!=0)
                pq.push(it);
        }
        int cnt=0;
        //remaining freq, time when available
        queue<pii> q;
        while(!pq.empty() || !q.empty()){
            cnt++;
            if(!q.empty() and q.front().second==cnt){
                pq.push(q.front().first);
                q.pop();
            }
            if(!pq.empty()){
                int f=pq.top();
                pq.pop();
                f--;
                if(f)
                    q.push({f,cnt+n+1});
            }
        }
        return cnt;
    }
};
