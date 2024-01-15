class Solution {
    /*
     1 -> 1, 0;
     2 -> 1, 0;
     3 -> 
    */
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, pair<int, int>> outcome_count;

        for(int i = 0; i < matches.size(); i++) {
            int winner = matches[i][0];
            int looser = matches[i][1];

            outcome_count[winner].first += 1;
            outcome_count[looser].second += 1;
        }

        vector<int> loss_0;
        vector<int> loss_1;

        for(auto it: outcome_count) {
            if(it.second.second == 0) loss_0.push_back(it.first);
            if(it.second.second == 1) loss_1.push_back(it.first);
        }

        sort(loss_0.begin(), loss_0.end());
        sort(loss_1.begin(), loss_1.end());

        return {loss_0, loss_1};
    }
};