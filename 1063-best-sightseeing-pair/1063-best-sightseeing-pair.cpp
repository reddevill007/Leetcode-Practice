class Solution {

public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int ans = values[0];
        int n = values.size();
        vector<int> iMaxSoFar(n, 0);

        iMaxSoFar[0] = values[0];
        for(int i = 1; i < n; i++) {
            iMaxSoFar[i] = max(values[i] + i, iMaxSoFar[i - 1]);
        }

        for(int j = n - 1; j > 0; j--) {
            int score = iMaxSoFar[j - 1] + values[j] - j;
            ans = max(ans, score);
        }

        return ans;
    }
};