class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();

        vector<vector<unsigned int>> dp(n, vector<unsigned int>(amount + 1));

        for (int ind = 0; ind < n; ind++) {
            dp[ind][0] = 1;
        }

        for (int target = 0; target <= amount; target++) {
            if (target % coins[0] == 0) {
                dp[0][target] = 1;
            } else {
                dp[0][target] = 0;
            }
        }

        for (int ind = 1; ind < n; ind++) {
            for (int target = 1; target <= amount; target++) {
                unsigned int pick = 0;
                if (target >= coins[ind]) {
                    pick = dp[ind][target - coins[ind]];
                }
                unsigned int notpick = dp[ind - 1][target];

                dp[ind][target] = pick + notpick;
            }
        }
        return dp[n - 1][amount];
    }
};