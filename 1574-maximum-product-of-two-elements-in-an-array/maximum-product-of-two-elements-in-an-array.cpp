class Solution {
public:
    int maxProduct(vector<int>& arr) {
        int n = arr.size();

        sort(begin(arr), end(arr));

        int first_max = arr[n - 1];
        int second_max = arr[n - 2];

        return (first_max - 1)*(second_max - 1);
    }
};