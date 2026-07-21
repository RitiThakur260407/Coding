class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size() ;
        vector<vector<int>> maxEff(n, vector<int>(m, 1e9));
        int delrow[] = {-1, 0, 0, 1};
        int delcol[] = {0, 1, -1, 0};

        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;

        pq.push({0, {0, 0}});
        maxEff[0][0] = 0;

        while (!pq.empty()) {
            int currEff = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;

            pq.pop();

            for (int i = 0; i < 4; i++) {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if ((nrow >= 0) && (nrow < n) && (ncol >= 0) && (ncol < m)) {
                    int eff = abs(heights[nrow][ncol] - heights[row][col]);

                    eff = max(eff, currEff);

                    if (eff < maxEff[nrow][ncol]) {
                        maxEff[nrow][ncol] = eff;

                        pq.push({eff, {nrow, ncol}});
                    }
                }
            }
        }

        return maxEff[n - 1][m - 1];
    }
};