class Solution {
public:
    int paths(int row, int col, int m, int n,
              vector<vector<int>>& obstacleGrid , vector<vector<int>>& dp) {
        if ((row >= m) || (col >= n))
            return 0;

        if (obstacleGrid[row][col] == 1)
            return 0;

        if ((row == m - 1) && (col == n - 1))
            return 1;

        if(dp[row][col] != -1)
        return dp[row][col] ;

        int path1 = paths(row + 1, col, m, n, obstacleGrid ,dp);
        int path2 = paths(row, col + 1, m, n, obstacleGrid,dp);

        return dp[row][col] = (path1 + path2);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>> dp(m,vector<int>(n,-1)) ;

        return paths(0, 0, m, n, obstacleGrid,dp);
    }
};