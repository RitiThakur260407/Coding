class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size() ;
        vector<vector<int>> ans ;
        int i = 0 , start = newInterval[0] , end = newInterval[1] ;
        while((i < n) && (intervals[i][1] < start))
        {
            ans.push_back(intervals[i]) ;
            i++ ;
        }

        while((i < n) && (intervals[i][0] <= end))
        {
            start = min(start , intervals[i][0]) ;
            end = max(end,intervals[i][1]) ;
            i++ ;
        }

        ans.push_back({start,end}) ;

        while(i < n)
        {
            ans.push_back(intervals[i]) ;
            i++ ;
        }

        return ans ;
    }
};