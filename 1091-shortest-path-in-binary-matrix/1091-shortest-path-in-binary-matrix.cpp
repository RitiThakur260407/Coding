class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        if ((grid[0][0] == 1) || (grid[n - 1][n - 1] == 1))
            return -1;

        queue<pair<int, int>> q;

        vector<vector<int>> dist(n, vector<int>(n, -1));

        q.push({0, 0});
        dist[0][0] = 1;

        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    int nrow = row + i;
                    int ncol = col + j;

                    if ((nrow >= 0) && (nrow < n) && (ncol >= 0) &&
                        (ncol < n)) {
                        if ((dist[nrow][ncol] == -1) && (grid[nrow][ncol] == 0)) {
                            dist[nrow][ncol] = 1 + dist[row][col];
                            q.push({nrow, ncol});
                        }
                    }
                }
            }
        }

        return dist[n - 1][n - 1];
    }
};