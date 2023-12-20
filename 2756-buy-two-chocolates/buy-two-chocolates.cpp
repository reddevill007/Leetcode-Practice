class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        sort(prices.begin(), prices.end());

        int leastSum = prices[0] + prices[1];

        if(leastSum > money) return money;
        return money - leastSum;
    }
};