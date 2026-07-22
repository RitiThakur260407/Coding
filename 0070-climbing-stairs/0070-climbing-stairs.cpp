class Solution {
public:
    int steps(int ind, int n, vector<int>& dp) {
        if (ind > n)
            return 0;

        if (ind == n)
            return 1;

        if (dp[ind] != -1)
            return dp[ind];

        return dp[ind] = steps(ind + 1, n, dp) + steps(ind + 2, n, dp);
    }
    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);
        return steps(0, n, dp);
    }
};