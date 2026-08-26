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
        //time,user,index
        using T=tuple<int,int,int>;
        priority_queue<T> pq;
        follower[userId].insert(userId);
        for(auto& x:follower[userId]){
            if(tweet[x].empty())
                continue;
            int ind=tweet[x].size()-1;
            int times=tweet[x][ind].first;
            pq.push({times,x,ind});
        }
        while(!pq.empty() and ans.size()<10){
            auto [times,user,ind]=pq.top();
            pq.pop();
            ans.push_back(tweet[user][ind].second);
            if(ind>0){
                ind--;
                int newtimes=tweet[user][ind].first;
                pq.push({newtimes,user,ind});
            }
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
