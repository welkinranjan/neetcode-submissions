class Solution {
   public:
    int evalRPN(vector<string>& v) {
        stack<int> st;
        int n = v.size();
        for (auto& val : v) {
            if (val == "+" || val == "-" || val == "*" || val == "/") {
                int val2 = st.top();
                st.pop();
                int val1 = st.top();
                st.pop();
                if (val == "+") {
                    st.push(val1 + val2);
                }
                if (val == "-") {
                    st.push(val1 - val2);
                }
                if(val == "*") { st.push(val1 * val2); }
                if(val == "/") { st.push(val1 / val2); }
            }
            else
                st.push(stoi(val));
        }
        return st.top();
    }
};
