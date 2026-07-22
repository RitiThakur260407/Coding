class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n);

        for (int i = 0; i < n; i++) {
            dp[i] = vector<int>(i + 1, -1);
        }

        for (int i = 0; i < n; i++) {
            dp[n - 1][i] = triangle[n - 1][i];
        }

        for (int row = n - 2; row >= 0; row--) {
            for (int col = row; col >= 0; col--) {
                dp[row][col] = triangle[row][col] +
                               min(dp[row + 1][col], dp[row + 1][col + 1]);
            }
        }
        return dp[0][0];
    }
};