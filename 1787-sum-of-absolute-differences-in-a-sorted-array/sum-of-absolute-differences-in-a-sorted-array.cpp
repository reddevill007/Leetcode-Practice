class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        /*
            nums -> sorted in non decending order
            res -> same len (res[i] = sum(|nums[i]-nums[j]|))

            eg -> nums = [2, 3, 5] => 10
                  ans = [4, 3, 5]
                  prefix = [2, 5, 10]
                  suffix = [10, 8, 5]

            eg -> nums = [1, 4, 6, 8, 10]
                  ans  = [24, 15, 13, 15, 21]
                  prefix = [1, 5, 11, 19, 29]
                  suffix = [29, 28, 24, 18, 10]

            formula: res[i] = nums[i]*i - leftSum + rightSum - nums[i]*(n - i - 1)

        */
        int n = nums.size();
        vector<int> res(n);
        vector<int> prefix(n);

        prefix[0] = nums[0];

        for(int i = 1; i < n; i++) {
            prefix[i] = nums[i] + prefix[i - 1];
        }

        for(int i = 0; i < n; i++) {
            int leftSum = prefix[i] - nums[i];
            int rightSum = prefix[n - 1] - prefix[i];

            res[i] = nums[i]*i - leftSum + rightSum - nums[i]*(n - i - 1);
        }

        return res;
    }
};