class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> stringMap;

        for(string st: strs) {
            string temp = st;
            sort(temp.begin(), temp.end());
            stringMap[temp].push_back(st);
        }

        vector<vector<string>> ans;

        for(auto mp: stringMap) {
            ans.push_back(mp.second);
        }

        return ans;
    }
};