class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorr = 0;

        for(auto it: nums) {
            xorr = xorr ^ it;
        }

        int cnt = 0;

        while(xorr) {
            if(xorr & 1) break;
            cnt++;
            xorr = xorr >> 1;
        }

        int xorr1 = 0, xorr2 = 0;

        for(auto it: nums) {
            if(it & (1 << cnt)) {
                xorr1 = xorr1 ^ it;
            }
            else {
                xorr2 = xorr2 ^ it;
            }
        }

        return {xorr1, xorr2};
    }
};