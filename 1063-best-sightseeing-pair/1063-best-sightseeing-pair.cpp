class Solution {

public:
    int maxScoreSightseeingPair(vector<int>& v) {
        int ans = v[0];
        int n = v.size();

        int maxLeftScore = v[0];

        for(int i = 1; i < n; i++) {
            int currRightScore = v[i] - i;
            ans = max(ans, currRightScore + maxLeftScore);
            int currLeftScore = v[i] + i;
            maxLeftScore = max(maxLeftScore, currLeftScore);
        }

        return ans;
    }
};