class Solution {
public:
    int findMin(vector<int> &nums) {
        int n=nums.size();
        if(nums[n-1]>nums[0])
            return nums[0];
        int low=0,high=n-1,ans=0;
        while(low<high){
            int mid=low+(high-low)/2;
            int val=nums[mid];
            if(val>nums[high])
                low=mid+1;
            else{
                high=mid;
            }
        }
        return nums[high];
    }
};
