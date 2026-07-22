class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> dp(n + 1, 1e9);

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if ((i == m - 1) && (j == n - 1)) {
                    dp[j] = grid[i][j];
                    continue;
                }

                int path1 = dp[j];
                int path2 = dp[j + 1];

                dp[j] = grid[i][j] + min(path1, path2);
            }
        }

        return dp[0];
    }
};