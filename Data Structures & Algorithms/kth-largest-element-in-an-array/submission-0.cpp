class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> minh;
        for(const auto& t:nums){
            minh.push(t);
            if(minh.size()>k)
                minh.pop();
        }
        return minh.top();
    }
};
