class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> minh;
    int p;
    KthLargest(int k, vector<int>& nums) {
        int n=nums.size();
        p=k;
        for(auto it:nums){
            minh.push(it);
            if(minh.size()>k)
                minh.pop();
        }
    }
    
    int add(int it) {
        minh.push(it);
        if(minh.size()>p)
            minh.pop();
        return minh.top();
    }
};
