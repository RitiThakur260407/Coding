class Solution {
public:
    void bfs(int row, int col, vector<vector<char>>& grid,
             vector<vector<int>>& visited) {
        int m = grid.size();
        int n = grid[0].size();

        int delrow[] = {-1, 0, 0, 1};
        int delcol[] = {0, 1, -1, 0};

        queue<pair<int, int>> q;
        q.push({row, col});
        visited[row][col] = 1;

        while (!q.empty()) {
            int curr_row = q.front().first;
            int curr_col = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nrow = curr_row + delrow[i];
                int ncol = curr_col + delcol[i];

                if ((nrow >= 0) && (nrow < m) && (ncol >= 0) && (ncol < n)) {
                    if ((grid[nrow][ncol] == '1') &&
                        (visited[nrow][ncol] == 0)) {
                        q.push({nrow, ncol});
                        visited[nrow][ncol] = 1;
                    }
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    if (visited[i][j] == 0) {
                        count++;
                        bfs(i, j, grid, visited);
                    }
                }
            }
        }
        return count;
    }
};