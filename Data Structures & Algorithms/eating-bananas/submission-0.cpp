class Solution {
public:


    bool check(int mid,int h,vector<int> &piles){
        int count=0;
        for(auto it:piles){
            count+=(it+mid-1)/mid;
            if(count>h)
                return 0;
        }
        return 1;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1,high=1e9+7,ans=1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(check(mid,h,piles)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};
