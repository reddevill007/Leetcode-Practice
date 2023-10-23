class Solution {
    int n;
    // int dp[1001][1001];

    bool checkPredecessor(string prevWord, string currWord) {
        int M = prevWord.length();
        int N = currWord.length();

        if(M >= N || N - M != 1) {
            return false;
        }

        int i = 0, j = 0;

        while(i < M && j < N) {
            if(prevWord[i] == currWord[j]) {
                i++;
            }
            j++;
        }

        return i == M;
    }

    // int solve(int prev, int curr, vector<string>& words) {
    //     if(curr == n) return 0;

    //     if(prev != -1 && dp[curr][prev] != -1) return dp[curr][prev];

    //     int take = 0;
    //     if(prev == -1 || checkPredecessor(words[prev], words[curr])) {
    //         take = 1 + solve(curr, curr + 1, words);
    //     }

    //     int skip = solve(prev, curr + 1, words);

    //     if(prev != -1) {
    //         dp[curr][prev] = max(skip, take);
    //     }

    //     return max(skip, take);
    // }

    static bool myFunction(string& a, string& b) {
        return a.length() < b.length();
    }

public:
    int longestStrChain(vector<string>& words) {
        int n  = words.size();
        // memset(dp, -1, sizeof(dp));
        sort(begin(words), end(words), myFunction);
        // return solve(-1, 0, words);

        vector<int> t(n, 1);
        int maxL = 1;
        
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<i; j++) {
                
                if(checkPredecessor(words[j], words[i])) {
                    t[i] = max(t[i], t[j]+1);
                    maxL = max(maxL, t[i]);
                }
            }
        }
        
        return maxL;        
    }
};