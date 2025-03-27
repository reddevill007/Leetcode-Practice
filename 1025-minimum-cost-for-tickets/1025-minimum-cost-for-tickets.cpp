class Solution {
    int dp[366];
private: 
    int solve(int idx, vector<int>& days, vector<int>& costs) {
        // base case
        if(idx >= days.size()) return 0;
        if(dp[idx] != -1) return dp[idx];
        // 1 day cost
        int cost_1 = costs[0] + solve(idx + 1, days, costs);

        // 7 day cost
        int j = idx;
        int max_day = days[idx] + 7;
        while(j < days.size() && days[j] < max_day) j++;
        int cost_7 = costs[1] + solve(j, days, costs);

        // 30 day cost
        j = idx;
        max_day = days[idx] + 30;
        while(j < days.size() && days[j] < max_day) j++;
        int cost_30 = costs[2] + solve(j, days, costs);

        return dp[idx] = min({cost_1, cost_7, cost_30});
    }

public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(dp, -1, sizeof(dp));
        return solve(0, days, costs);
    }
};