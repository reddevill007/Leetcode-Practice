class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();

        int l = 0;
        int r = n - 1;

        int mid;

        while(l < r) {
            mid = l + (r - l) / 2;

            if(arr[mid] < arr[mid + 1]) {
                l = mid + 1;
            }
            else {
                r = mid;
            }
        }

        return l;
    }
};