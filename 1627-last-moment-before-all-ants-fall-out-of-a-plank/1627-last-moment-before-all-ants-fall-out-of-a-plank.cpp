class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int maxAns = -1;
        for(int i = 0; i < left.size(); i++) {
            int currTime = left[i];
            maxAns = max(maxAns, currTime);
        }

        for(int i = 0; i < right.size(); i++) {
            int currTime = n - right[i];
            maxAns = max(maxAns, currTime);
        }

        return maxAns;
    }
};