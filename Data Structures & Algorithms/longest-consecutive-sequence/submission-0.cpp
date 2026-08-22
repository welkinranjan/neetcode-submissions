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
        unordered_map<int,bool> umap;
        for(const auto& x:nums)
            umap[x]=true;
        for( auto& x:nums){
            if(umap.find(x-1)==umap.end()){
                int count=1;
                while(umap.find(x+1)!=umap.end()){
                    x++;
                    count++;
                }
                ans=maxi(ans,count);
            }
        }
        return ans;
    }
};
