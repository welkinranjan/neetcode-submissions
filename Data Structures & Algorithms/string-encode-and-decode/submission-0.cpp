class Solution {
public:

    string encode(vector<string>& str) {
        string ans="";
        for(auto it:str){
            ans+=to_string(it.size())+"#";
            ans+=it;
        }
        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int n=s.size();
        int i=0;
        while(i<n){
            int j=i;
            while(s[j]!='#')
                j++;
            int len=stoi(s.substr(i,j-i));
            ans.push_back(s.substr(j+1,len));
            i=j+1+len;
        }
        return ans;
    }
};
