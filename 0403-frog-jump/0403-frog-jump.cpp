class Solution {
public:
    bool reach(int ind, int k, vector<int>& stones,
               unordered_map<int, int>& stand, vector<vector<int>>& dp) {

        int n = stand.size();

        if (ind == n - 1)
            return true;

        if (dp[ind][k] != -1)
            return dp[ind][k];

        for (int i = k + 1; i >= k - 1; i--) {
            int pos = stones[ind] + i;

            if (i <= 0)
                continue;

            if (stand.find(pos) != stand.end()) {
                if (reach(stand[pos], i, stones, stand, dp)) {
                    return dp[ind][k] = true;
                }
            }
        }

        return dp[ind][k] = false;
    }
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        unordered_map<int, int> stand;

        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        for (int i = 0; i < n; i++) {
            stand[stones[i]] = i;
        }

        return reach(0, 0, stones, stand, dp);
    }
};