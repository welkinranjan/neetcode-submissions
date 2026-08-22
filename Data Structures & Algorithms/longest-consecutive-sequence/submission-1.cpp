class Solution {
public:

    int maxi(int a,int b){
        return a>b?a:b;
    }

    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n<=1)
            return n;
        int ans=1;
        unordered_set<int> st;
        for(auto& x:nums)
            st.insert(x);
        for(auto& t:st){
            int x=t;
            if(!st.count(x-1)){
                int count=1;
                x++;
                while(st.count(x)){
                    x++;
                    count++;
                }
                ans=maxi(ans,count);
            }
        }
        return ans;
    }
};
