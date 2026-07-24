class Solution {
public:
    int ways(int ind, int amount, vector<int>& coins, vector<vector<int>>& dp) {
        if (amount == 0) {
            return 1;
        }

        if (ind == 0) {
            if (amount % coins[0] == 0) {
                return 1;
            }

            return 0;
        }

        if (dp[ind][amount] != -1)
            return dp[ind][amount];

        int pick = 0;
        if (amount >= coins[ind]) {
            pick = ways(ind, amount - coins[ind], coins, dp);
        }
        int notpick = ways(ind - 1, amount, coins, dp);

        return dp[ind][amount] = (pick + notpick);
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();

        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        return ways(n - 1, amount, coins, dp);
    }
};