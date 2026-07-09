class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int bp = prices[0], profit = 0;
        for (int i = 1; i < n; i++) {
            bp = min(bp, prices[i]);
            profit = max(profit, (prices[i] - bp));
        }
        return profit;
    }
};