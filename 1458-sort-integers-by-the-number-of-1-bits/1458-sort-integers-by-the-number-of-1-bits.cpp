class Solution {
        int find1bitsCount(int n) {
        int count = 0;

        while(n != 0) {
            count += n & 1;
            n = n >> 1;
        }
        return count;
    }

public:
    vector<int> sortByBits(vector<int>& arr) {

        auto lambda = [&] (int &a, int &b) {
            int CA = find1bitsCount(a);
            int CB = find1bitsCount(b);

            if(CA == CB) {
                return a < b;
            }

            return CA < CB;
        };

        sort(arr.begin(), arr.end(), lambda);

        return arr;
    }
};