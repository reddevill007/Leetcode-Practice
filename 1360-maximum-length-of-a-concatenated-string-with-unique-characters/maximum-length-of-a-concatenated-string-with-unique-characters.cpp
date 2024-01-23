class Solution {
    bool checkDup(string s1, string s2) {
        vector<int> char_ct(26, 0);

        for (auto ch : s1) {
            if (char_ct[ch - 'a'] > 0)
                return true;
            char_ct[ch - 'a']++;
        }

        for (auto ch : s2) {
            if (char_ct[ch - 'a'] > 0)
                return true;
        }

        return false;
    }

    int solve(int idx, vector<string>& arr, string temp, int n) {
        if (idx >= n)
            return temp.length();

        int take = 0;
        int not_take = 0;

        if (checkDup(arr[idx], temp)) {
            not_take = solve(idx + 1, arr, temp, n);
        } else {
            not_take = solve(idx + 1, arr, temp, n);
            take = solve(idx + 1, arr, temp + arr[idx], n);
        }

        return max(take, not_take);
    }

public:
    int maxLength(vector<string>& arr) {
        int n = arr.size();
        string temp = "";

        return solve(0, arr, temp, n);
    }
};