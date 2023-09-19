class Twitter {
public:
    map<int, set<int>> mp;
    int curr=0;
    priority_queue<vector<int>> pq;

    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        pq.push({curr++, tweetId, userId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        priority_queue<vector<int>> temp = pq;
        int n = 0;
        while(!temp.empty() && n < 10){
            auto it = temp.top();
            temp.pop();
            if(it[2] == userId ||  mp[userId].count(it[2])){
                ans.push_back(it[1]);
                n++;
            }
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        mp[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        mp[followerId].erase(followeeId);
    }
};