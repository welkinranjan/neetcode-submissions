class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26,0);
        int i=0,max_freq=0,ans=0,n=s.size();
        for(int j=0;j<n;++j){
            freq[s[j]-'A']++;
            max_freq=max(max_freq,freq[s[j]-'A']);
            //window size-max freq
            int need=j-i+1-max_freq;
            while(need>k){
                freq[s[i]-'A']--;
                i++;
                need=j-i+1-max_freq;
            }
            ans=max(ans,j-i+1);
        }
        return ans;
    }
};
