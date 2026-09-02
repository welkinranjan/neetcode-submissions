class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> umap;
        int i=0,j=0,n=s.size(),ans=0;
        while(j<n){
            umap[s[j]]++;
            while(umap[s[j]]>1){
                umap[s[i]]--;
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};
