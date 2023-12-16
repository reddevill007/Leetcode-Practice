class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int N = nums.size();
        vector<int> prefix(N);
        vector<int> suffix(N);
        vector<int> ans(N);

        prefix[0] = 1;
        suffix[N - 1] = 1;

        for(int i = 1; i < N; i++) {
            prefix[i] = nums[i - 1] * prefix[i - 1];
        }
        
        for(int i = N - 2; i >= 0; i--) {
            suffix[i] = nums[i + 1] * suffix[i + 1];
        }


        for(int i = 0; i < N; i++) {
            ans[i] = prefix[i] * suffix[i];
        }

        return ans;
    }
};