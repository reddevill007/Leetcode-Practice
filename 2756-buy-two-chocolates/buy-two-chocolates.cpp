class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int n = prices.size();
        int smallest = INT_MAX, secondSmallest = INT_MAX;

        for(int price: prices) {
            if(price < smallest) {
                secondSmallest = smallest;
                smallest = price;
            } else if(price < secondSmallest) {
                secondSmallest = price;
            }
        }

        int leastSum = smallest + secondSmallest;

        if(leastSum > money) return money;
        return money - leastSum;
    }
};