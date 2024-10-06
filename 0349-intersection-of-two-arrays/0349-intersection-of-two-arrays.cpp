class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_map<int, int> mp;
        set<int> st;

        for(auto it: nums1) {
            mp[it]++;
        }

        for(auto it: nums2) {  
            if(mp.find(it) != mp.end()) {
                ans.push_back(it);
                mp.erase(it);
            }
        }

        // for (auto itr : st) ans.push_back(itr);

        return ans;
    }
};