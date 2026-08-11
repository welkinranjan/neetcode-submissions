class Solution {
public:
    bool isValid(string s) {
        int len=s.size();
        if(len%2!=0)
            return 0;
        stack<char> st;
        for(int i=0;i<len;++i){
            if(s[i]=='('||s[i]=='['||s[i]=='{')
                st.push(s[i]);
            else{
                if(st.size()==0)
                    return 0;
                char ch=st.top();
                if((s[i]==')' and ch=='(') ||(s[i]=='}' and ch=='{')
                ||(s[i]==']' and ch=='['))
                    st.pop();
                else
                    return 0;
            }
        }
        if(st.empty())
            return 1;
        return 0;
    }
};
