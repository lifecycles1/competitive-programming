// Design a simplified version of Twitter where users can post tweets, follow/unfollow another user, 
// and is able to see the 10 most recent tweets in the user's news feed.

// Implement the Twitter class:

// Twitter() Initializes your twitter object.
// void postTweet(int userId, int tweetId) Composes a new tweet with ID tweetId by the user userId. 
// Each call to this function will be made with a unique tweetId.
// List<Integer> getNewsFeed(int userId) Retrieves the 10 most recent tweet IDs in the user's news feed. 
// Each item in the news feed must be posted by users who the user followed or by the user themself. 
// Tweets must be ordered from most recent to least recent.
// void follow(int followerId, int followeeId) The user with ID followerId started following the user 
// with ID followeeId.
// void unfollow(int followerId, int followeeId) The user with ID followerId started unfollowing the 
// user with ID followeeId.
 

// Design Twitter: post tweets, follow/unfollow, see recent tweets
// Maintain user -> tweet pairs & hash map {user -> ppl they follow}
// Time: O(n)
// Space: O(n)

#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Twitter {
public:
  Twitter() {}

  void postTweet(int userId, int tweetId) {
    posts.push_back({userId, tweetId});
  }

  vector<int> getNewsFeed(int userId) {
    // 10 tweets
    int count = 10;
    vector<int> result;

    // since postTweet pushes to the back, looping from back gets most recent
    for (int i = posts.size() - 1; i >= 0; i--) {
      if (count == 0) {
        break;
      }
      int followingId = posts[i].first;
      int tweetId = posts[i].second;
      unordered_set<int> following = followMap[userId];
      // add to result if they're following them or it's a tweet from themself
      if (following.find(followingId) != following.end() || followingId == userId) {
        result.push_back(tweetId);
        count--;
      }
    }
    return result;
  }
  
  void follow(int followerId, int followeeId) {
    followMap[followerId].insert(followeeId);
  }

  void unfollow(int followerId, int followeeId) {
    followMap[followerId].erase(followeeId);
  }

private:
  // pairs: [user, tweet]
  vector<pair<int, int>> posts;
  // hash map: {user -> people they follow}
  unordered_map<int, unordered_set<int>> followMap;
};


/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */