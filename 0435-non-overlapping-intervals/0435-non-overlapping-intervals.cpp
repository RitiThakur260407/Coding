class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),([](const vector<int>& a , const vector<int>& b)
        {
            return a[1] < b[1] ;
        }));
        int n = intervals.size() ;
        int st = INT_MIN , end = INT_MIN ;
        int count = 0 ;
        for(int i = 0 ; i < n ;i++)
        {
            int starti = intervals[i][0] ;
            int endi = intervals[i][1] ;
            if(end <= starti)
            {
                end = endi ;
            }
            else
            {
                count++ ;
            }
        }
        return count ;
    }
};