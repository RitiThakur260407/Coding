class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<long long>> dp(m + 1, vector<long long>(n + 1));

        for (int i = 0; i <= n; i++) {
            dp[m][i] = 0;
        }

        for (int row = m - 1; row >= 0; row--) {
            for (int col = n - 1; col >= 0; col--) {
                if (obstacleGrid[row][col] == 1) {
                    dp[row][col] = 0;
                    continue;
                }
                if (row == m - 1 && col == n - 1) {
                    dp[row][col] = 1;
                    continue;
                }
                long long path1 = dp[row + 1][col];
                long long path2 = dp[row][col + 1];

                dp[row][col] = path1 + path2;
            }
        }

        return (int)dp[0][0] ;
    }
};