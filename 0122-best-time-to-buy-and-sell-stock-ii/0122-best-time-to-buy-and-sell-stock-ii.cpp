class Solution {
public:
    int profit(int ind, int buy, int n, vector<int>& prices,
               vector<vector<int>>& dp) {
        if (ind == n)
            return 0;

        if (dp[ind][buy] != -1)
            return dp[ind][buy];

        if (buy == 0) {
            int take = -prices[ind] + profit(ind + 1, 1, n, prices, dp);
            int nottake = profit(ind + 1, 0, n, prices, dp);

            return dp[ind][0] = max(take, nottake);
        } else {
            int sell = prices[ind] + profit(ind + 1, 0, n, prices, dp);
            int notsell = profit(ind + 1, 1, n, prices, dp);

            return dp[ind][1] = max(sell, notsell);
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));

        return profit(0, 0, n, prices, dp);
    }
};