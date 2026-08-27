class Solution {
public:

    vector<vector<int>> ans;
    vector<int> v;

    void solve(vector<int>& nums,int i){
        //base
        if(i==nums.size()){
            ans.push_back(v);
            return;
        }
        //take and explore all possibilities
        v.push_back(nums[i]);
        solve(nums,i+1);
        //undo
        v.pop_back();
        //don't take
        solve(nums,i+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        solve(nums,0);
        return ans;
    }
};
