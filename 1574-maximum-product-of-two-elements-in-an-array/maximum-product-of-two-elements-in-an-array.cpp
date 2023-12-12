class Solution {
public:
    int maxProduct(vector<int>& arr) {
        int n = arr.size();

        int first_max = INT_MIN;
        int second_max = INT_MIN;

        for(int i = 0; i < n; i++) {
            if(arr[i] >= first_max) {
                second_max = first_max;
                first_max = arr[i];
            } else if(arr[i] > second_max) {
                second_max = arr[i];
            }
        }

        return (first_max - 1)*(second_max - 1);
    }
};