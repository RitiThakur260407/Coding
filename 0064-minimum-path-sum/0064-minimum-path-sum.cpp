class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> dp(n + 1, 1e9);

        for (int i = m - 1; i >= 0; i--) {
            vector<int> temp(n + 1, 1e9);
            for (int j = n - 1; j >= 0; j--) {
                if ((i == m - 1) && (j == n - 1)) {
                    temp[j] = grid[i][j];
                    continue;
                }

                int path1 = dp[j];
                int path2 = temp[j + 1];

                temp[j] = grid[i][j] + min(path1, path2);
            }
            dp = temp;
        }

        return dp[0];
    }
};