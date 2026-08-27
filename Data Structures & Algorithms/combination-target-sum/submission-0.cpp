class Solution {
public:
    vector<vector<int>> ans;
    vector<int> v;

    void solve(vector<int>& nums,int i,int target){
        //base
        if(target==0){
            ans.push_back(v);
            return;
        }
        if(i==nums.size()||target<0)
            return;
        //take and explore all possibilities
        v.push_back(nums[i]);
        solve(nums,i,target-nums[i]);
        //undo
        v.pop_back();
        //don't take
        solve(nums,i+1,target);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        solve(nums,0,target);
        return ans;       
    }
};
