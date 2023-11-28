class Solution {
    int MOD = 1e9 + 7;
public:
    int numberOfWays(string corridor) {
        vector<int> seat_idx;

        for(int i = 0; i < corridor.length(); i++) {
            if(corridor[i] == 'S') {
                seat_idx.push_back(i);
            }
        }

        if(seat_idx.size() % 2 != 0 || seat_idx.size() == 0) {
            return 0;
        }

        int prev_end_idx = seat_idx[1];
        long long res = 1;

        for(int i = 2; i < seat_idx.size(); i+=2) {
            int len = seat_idx[i] - prev_end_idx;

            res = (res*len) % MOD;

            prev_end_idx = seat_idx[i + 1];
        }

        return res;
    }
};