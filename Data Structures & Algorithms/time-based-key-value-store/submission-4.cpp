class TimeMap {
public:
    using pis=pair<int,string>;
    unordered_map<string,vector<pis>> umap;

    TimeMap() {
        umap.clear();
    }
    
    void set(string key, string value, int timestamp) {
        umap[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        if(umap.find(key)==umap.end())
            return "";
        auto &v=umap[key];
        int n=v.size();
        int low=0,high=n-1;
        string ans="";
        while(low<=high){
            int mid=low+(high-low)/2;
            int val=v[mid].first;
            if(val<=timestamp){
                ans=v[mid].second;
                low=mid+1;
            }
            else
                high=mid-1;
        }
        return ans;
    }
};
