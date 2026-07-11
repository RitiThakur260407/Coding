class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n == 1) {
            return intervals;
        }
        vector<vector<int>> ans;
        
        sort(intervals.begin(), intervals.end(),
             ([](const vector<int>& a, const vector<int>& b) {
                 return a[0] < b[0];
             }));

        int start = intervals[0][0], end = intervals[0][1];
        for (int i = 1; i < n; i++) {
            int starti = intervals[i][0];
            int endi = intervals[i][1];
            if (starti <= end) {
                start = min(starti, start);
                end = max(endi, end);
            } else {
                ans.push_back({start, end});
                start = starti;
                end = endi;
            }
        }
        ans.push_back({start, end});
        return ans;
    }
};