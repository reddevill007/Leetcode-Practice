class Solution {
    int binary_search(vector<int> nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while(left < right) {
            int mid = (left + right) / 2;

            if(nums[mid] < target) left = mid + 1;
            else right = mid;
        }

        return left;
    }

public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        if(n == 0) return {-1, -1};

        int i = binary_search(nums, target);

        if(nums[i] != target) return {-1, -1};

        int j = binary_search(nums, target + 1);
        if(nums[j] == target) return {i, j};
        return {i, j - 1};
    }
};