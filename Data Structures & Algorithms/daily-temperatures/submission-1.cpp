class Solution {
public:

    #define pii pair<int,int>
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n=temp.size();
        vector<int> ans;
        int a[n];
        stack<pii> st;
        for(int i=0;i<n;++i)
            a[i]=0;
        for(int i=0;i<n;++i){
            while(!st.empty() and st.top().first<temp[i]){
                a[st.top().second]=i-st.top().second;
                st.pop();
            }
            st.push({temp[i],i});
        }
        for(int i=0;i<n;++i)
            ans.push_back(a[i]);
        return ans;
    }
};
