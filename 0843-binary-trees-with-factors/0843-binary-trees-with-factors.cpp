class Solution {
    int MOD = 1e9 + 7;
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n = arr.size();
        sort(begin(arr), end(arr));

        unordered_map<int, long long> tree_count;

        for(int i = 0; i < n; i++) {
            tree_count[arr[i]] = 1;
        }

        for(int i = 1; i < n; i++) {
            int root = arr[i];
            for(int j = 0; j < i; j++) {
                int lc = arr[j];
                int rc = root / lc;

                if(root % lc == 0 && tree_count.find(rc) != tree_count.end()) {
                    tree_count[root] = tree_count[root] + tree_count[lc]*tree_count[rc];
                }
            }
        }

        long ans = 0;
        for(int i = 0; i < n; i++) {
            ans = (ans + tree_count[arr[i]]) % MOD;
        }

        return ans;
    }
};