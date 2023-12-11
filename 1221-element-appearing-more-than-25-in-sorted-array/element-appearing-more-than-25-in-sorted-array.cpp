class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        int count = 1;
        int prev = arr[0];
        int req_cnt = n / 4;

        for(int i = 1; i < n; i++) {
            if(prev == arr[i]) count++;
            else {
                count = 1;
            }

            if(count > req_cnt) return arr[i];
            prev = arr[i];
        }

        return prev;
    }
};