class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        unordered_map<int, int> el_count;

        for(auto it: arr) {
            el_count[it]++;
        }

        int thresh_hold = arr.size() / 4;

        for(auto it: el_count) {
            if(it.second > thresh_hold) return it.first;
        }

        return -1;
    }
};