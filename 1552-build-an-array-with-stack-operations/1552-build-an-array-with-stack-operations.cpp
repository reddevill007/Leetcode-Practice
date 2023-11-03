class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int currIdx = 0;

        for(int i = 1; i <= n; i++) {
            if(currIdx == target.size()) break;
            if(target[currIdx] == i) {
                ans.push_back("Push");
                currIdx++;
            } else {
                ans.push_back("Push");
                ans.push_back("Pop");
            }
        }

        return ans;
    }
};