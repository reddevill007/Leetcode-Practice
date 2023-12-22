class Solution {
public:
    int maxScore(string s) {
        int currZeroCt = 0;
        int currOneCt = 0;
        int totalOnes = 0;
        int maxScore = -1;

        for(int i = 0; i < s.length(); i++) {
            char ch = s[i];
            if(ch == '1') totalOnes++;
        }

        for(int i = 0; i < s.length() - 1; i++) {
            char ch = s[i];

            if(ch == '1') currOneCt++;
            if(ch == '0') currZeroCt++;

            int rightOnesCt = totalOnes - currOneCt;

            int currScore = currZeroCt + rightOnesCt;

            maxScore = max(maxScore, currScore);
        }

        return maxScore;
    }
};