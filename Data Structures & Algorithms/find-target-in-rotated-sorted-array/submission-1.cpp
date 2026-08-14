class Solution {
public:

    int bs(vector<int>& nums,int target,int low,int high){
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target)
                return mid;
            if(nums[mid]>target)
                high=mid-1;
            else
                low=mid+1;
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        int n=nums.size();
        if(nums[n-1]>nums[0]){
            return bs(nums,target,0,n-1);
        }
        int low=0,high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int val=nums[mid];
            if(val==target)
                return mid;
            //left half is sorted
            if(nums[low]<=val){
                if(nums[low]<=target and target<val)
                    high=mid-1;
                else
                    low=mid+1;
            }
            else{
                if(nums[high]>=target and val<target)
                    low=mid+1;
                else
                    high=mid-1;
            }  
        }
        return -1;
    }
};
