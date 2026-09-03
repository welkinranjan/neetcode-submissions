class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> freq1(26,0),freq2(26,0);
        int n1=s1.size(),n2=s2.size();
        if(n1>n2)
            return 0;
        for(auto& x:s1)
            freq1[x-'a']++;
        int i=0,j=0;
        while(j<n2){
            freq2[s2[j]-'a']++;
            if(j-i+1==n1){
                if(freq1==freq2)
                    return 1;
                freq2[s2[i]-'a']--;
                i++;
            }
            j++;
        }
        return 0;
    }
};
