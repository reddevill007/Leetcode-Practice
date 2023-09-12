class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> res;

        int left1 = 0;
        int left2 = 0;

        while(left1 < m && left2 < n) {
            if(nums1[left1] <= nums2[left2]) {
                res.push_back(nums1[left1]);
                left1++;
            } else {
                res.push_back(nums2[left2]);
                left2++;
            }
        }

        while(left1 < m) {
            res.push_back(nums1[left1]);
            left1++;
        }
        
        while(left2 < n) {
            res.push_back(nums2[left2]);
            left2++;
        }

        for(int i = 0; i < nums1.size(); i++) {
            nums1[i] = res[i];
        }
    }
};