class Solution {
public:
    int paths(int row, int col, int m, int n, vector<vector<int>>& dp) {
        if ((row >= m) || (col >= n))
            return 0;

        if ((row == m - 1) && (col == n - 1))
            return 1;

        if (dp[row][col] != -1)
            return dp[row][col];

        return dp[row][col] = paths(row, col + 1, m, n, dp) +
                              paths(row + 1, col, m, n, dp);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        dp[m - 1][n - 1] = 1;

        for (int row = m - 1; row >= 0; row--) {
            for (int col = n - 1; col >= 0; col--) {
                if (row == m - 1 && col == n - 1)
                    continue;

                dp[row][col] = dp[row][col + 1] + dp[row + 1][col];
            }
        }

        return dp[0][0];
    }
};