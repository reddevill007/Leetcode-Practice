class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero = 0;
        int one = 0;
        int two = 0;

        for(auto it: nums) {
            if(it == 0) zero++;
            if(it == 1) one++;
            if(it == 2) two++;
        }

        int idx = 0;

        while(zero--) {
            nums[idx] = 0;
            idx++;
        }

        while(one--) {
            nums[idx] = 1;
            idx++;
        }

        while(two--) {
            nums[idx] = 2;
            idx++;
        }
    }
};