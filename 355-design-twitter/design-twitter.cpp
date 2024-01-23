class Twitter {
    unordered_map<int, unordered_set<int>> follower;
    vector<pair<int, int>> posts;

public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        posts.push_back({userId, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> userPost;

        for(int i = posts.size() - 1; i >= 0; i--) {
            if(userPost.size() > 9) break;

            int postUserId = posts[i].first;
            if(postUserId == userId || follower[userId].count(postUserId) > 0) {
                userPost.push_back(posts[i].second);
            }
        }

        return userPost;
    }
    
    void follow(int followerId, int followeeId) {
        follower[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        follower[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */