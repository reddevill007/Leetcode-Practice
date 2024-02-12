class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int key = 0, count = 0;

        for(auto x: nums) {
            if(count == 0) key = x;

            if(x == key) count++;
            else count--;
        }

        return key;
    }
};