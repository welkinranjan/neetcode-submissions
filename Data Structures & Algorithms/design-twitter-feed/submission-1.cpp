class Twitter {
public:
    using pii=pair<int,int>;
    int time=0;
    //followerid---followeeids
    unordered_map<int,unordered_set<int>> follower;
    //userid---{time,tweetid}
    //tweets data
    unordered_map<int,vector<pii>> tweet;

    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        time++;
        tweet[userId].push_back({time,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        priority_queue<pii> pq;
        follower[userId].insert(userId);
        auto& t=follower[userId];
        for(auto& x:t){
            auto &p=tweet[x];
            for(auto &it:p){
                pq.push({it.first,it.second});
            }
        }
        while(!pq.empty() and ans.size()<10){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        follower[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        follower[followerId].erase(followeeId);
    }
};
