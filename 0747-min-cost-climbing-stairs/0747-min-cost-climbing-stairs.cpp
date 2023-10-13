class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int prev1 = 0, prev2 = 0;

        for(int i = 2; i <= n; i++) {
            int curr_cost = min(prev1 + cost[i - 1], prev2 + cost[i - 2]);
            prev2 = prev1;
            prev1 = curr_cost;
        }

        return prev1;
    }
};