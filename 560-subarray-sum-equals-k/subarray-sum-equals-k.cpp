class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        int ans = 0;

        unordered_map<int, int> sum_map;
        sum_map[sum] = 1;

        for(int i = 0; i < n; i++) {
            sum += nums[i];
            int x = sum - k;

            if(sum_map[x] > 0) {
                ans += sum_map[x];
            }
            
            sum_map[sum]++;
        }

        return ans;
    }
};