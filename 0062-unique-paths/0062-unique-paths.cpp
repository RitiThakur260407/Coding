class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n+1,0);
        dp[n - 1] = 1;

        for (int row = m - 1; row >= 0; row--) {
            vector<int> temp(n+1,0) ; 
            for (int col = n - 1; col >= 0; col--) {
                temp[col] = temp[col + 1] + dp[col];
            }
            dp = temp ;
        }

        return dp[0];
    }
};