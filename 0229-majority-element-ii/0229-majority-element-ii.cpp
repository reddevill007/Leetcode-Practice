class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int me_1 = 0, me_2 = 0;
        int c1 = 0, c2 = 0;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == me_1) {
                c1++;
            } 
            else if(nums[i] == me_2) {
                c2++;
            } else if(c1 == 0 && nums[i] != me_2) {
                me_1 = nums[i];
                c1 = 1;
            } else if(c2 == 0 && nums[i] != me_1) {
                me_2 = nums[i];
                c2 = 1;
            } else {
                c1--;
                c2--;
            }
        }

        vector<int> ans;
        int n = nums.size() / 3;
        c1 = 0, c2 = 0;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == me_1) c1++;
            else if(nums[i] == me_2) c2++;
        }

        if(c1 > n) ans.push_back(me_1);
        if(c2 > n) ans.push_back(me_2);

        return ans;
    }
};