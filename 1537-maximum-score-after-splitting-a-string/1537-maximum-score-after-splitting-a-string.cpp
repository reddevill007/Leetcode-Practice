class Solution {
public:
    int maxScore(string s) {
        int n = s.length();
        vector<int> leftScore(n, 0);
        vector<int> rightScore(n, 0);

        int i = 0;
        int j = n - 1;

        while(i < n && j > 0) {
            if(s[i] == '0') {
                leftScore[i] = i != 0 ? leftScore[i - 1] + 1: 1;
            } else {
                leftScore[i] = i != 0 ? leftScore[i - 1]: 0;
            }

            if(s[j] == '1') {
                rightScore[j] = j != n - 1 ? rightScore[j + 1] + 1: 1;
            } else {
                rightScore[j] = j != n - 1 ? rightScore[j + 1]: 0;
            }
            i++;
            j--;
        }

        int ans = 0;

        for(int i = 1; i < n; i++) {
            int currAns = rightScore[i] + leftScore[i - 1];
            ans = max(ans, currAns);
        }

        return ans;
    }
};