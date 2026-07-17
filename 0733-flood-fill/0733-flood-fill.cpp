class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        int m = image.size();
        int n = image[0].size();
        int delrow[] = {-1, 0, 0, 1};
        int delcol[] = {0, 1, -1, 0};

        int original = image[sr][sc];
        
        if(original == color)
        return image ;

        image[sr][sc] = color;

        queue<pair<int, int>> q;
        q.push({sr, sc});

        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if ((nrow >= 0) && (nrow < m) && (ncol >= 0) && (ncol < n)) {
                    if (image[nrow][ncol] == original) {
                        q.push({nrow, ncol});
                        image[nrow][ncol] = color;
                    }
                }
            }
        }

        return image;
    }
};