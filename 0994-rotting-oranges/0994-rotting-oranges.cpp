class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size() ;
        int n = grid[0].size() ;
        int delrow[] = {-1,0,0,1} ;
        int delcol[] = {0,1,-1,0} ;

        queue<pair<int,int>> q ;
        int fresh = 0 , time = 0 ;

        for(int i = 0 ; i < m ; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                if(grid[i][j] == 2)
                {
                    q.push({i,j}) ;
                }
                else if(grid[i][j] == 1)
                {
                    fresh++ ;
                }
            }
        }

        if(fresh == 0)
        return 0 ;

        while(!q.empty())
        {
            int size = q.size() ;

            for(int i = 0 ; i < size ; i++)
            {
                int row = q.front().first ;
                int col = q.front().second ;
                q.pop() ;

                for(int j = 0 ; j < 4 ; j++)
                {
                    int nrow = row + delrow[j] ;
                    int ncol = col + delcol[j] ;

                    if((nrow >= 0) && (nrow < m) && (ncol >= 0) && (ncol < n))
                    {
                        if(grid[nrow][ncol] == 1)
                        {
                            grid[nrow][ncol] = 2 ;
                            fresh-- ;
                            q.push({nrow,ncol}) ;
                        }
                    }
                }
            }

            time++ ;
        }
        if(fresh != 0)
        {
            return -1 ;
        }

        return time-1 ;
    }
};