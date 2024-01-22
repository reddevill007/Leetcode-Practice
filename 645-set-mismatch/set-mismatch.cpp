class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int, int> mp;
        int n = nums.size();
        
        for(auto it: nums) {
            mp[it]++;
        }

        int rep_num = -1;
        int not_present = -1;

        for(int i = 1; i <= n; i++) {
            if(mp.find(i) == mp.end()) not_present = i;
            else if(mp.find(i)->second == 2) rep_num = mp.find(i)->first;
        }

        return {rep_num, not_present};
    }
};