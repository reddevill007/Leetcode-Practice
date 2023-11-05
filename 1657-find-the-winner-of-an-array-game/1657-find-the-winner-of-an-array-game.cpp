class Solution {
    void leftShift(vector<int> &arr, int l, int r) {
        for(int i = l; i < r - 1; i++) {
            swap(arr[i], arr[i + 1]);
        }
    }

public:
    int getWinner(vector<int>& arr, int k) {
        int n = arr.size();
        int maxEl = *max_element(begin(arr), end(arr));
        if(k >= n) {
            return maxEl;
        }

        int win_count = 0;
        int winner = arr[0];

        for(int i = 1; i < n; i++) {
            if(arr[i] > winner) {
                win_count = 1;
                winner = arr[i];
            }
            else {
                win_count++;
            }

            if(win_count == k || winner == maxEl) {
                return winner;
            }
        }

        return winner;
    }
};