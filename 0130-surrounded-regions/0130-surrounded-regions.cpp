class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>& visited,
             vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        visited[row][col] = 1;

        int delrow[] = {-1, 0, 0, 1};
        int delcol[] = {0, 1, -1, 0};

        for (int i = 0; i < 4; i++) {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if ((nrow >= 0) && (nrow < m) && (ncol >= 0) && (ncol < n)) {
                if (board[nrow][ncol] == 'O' && (visited[nrow][ncol] == 0)) {
                    dfs(nrow, ncol, visited, board);
                }
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if ((i == 0) || (i == m - 1) || (j == 0) || (j == n - 1)) {
                    if ((board[i][j] == 'O') && (visited[i][j] == 0)) {
                        dfs(i, j, visited, board);
                    }
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if ((visited[i][j] == 0) && (board[i][j] == 'O')) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};