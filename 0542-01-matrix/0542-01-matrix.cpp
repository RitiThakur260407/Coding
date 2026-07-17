class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size() ;
        int n = mat[0].size() ;
        int delrow[] = {-1,0,0,1} ;
        int delcol[] = {0,1,-1,0} ;

        int dist = 0 ;
        queue<pair<int,int>> q ;
        vector<vector<int>> vis(m,vector<int>(n,0)) ;

        for(int i = 0 ; i < m ; i++)
        {
            for(int j = 0; j < n ;j++)
            {
                if(mat[i][j] == 0)
                {
                    q.push({i,j}) ;
                    vis[i][j] = 1;
                }
            }
        }

        while(!q.empty())
        {
            int size = q.size() ;

            for(int i = 0 ; i < size ; i++)
            {
                int row = q.front().first ;
                int col = q.front().second ;
                q.pop() ;

                mat[row][col] = dist ;

                for(int j = 0 ; j < 4 ; j++)
                {
                    int nrow = row + delrow[j] ;
                    int ncol = col + delcol[j] ;

                    if((nrow >= 0) && (nrow < m) && (ncol >= 0) && (ncol < n))
                    {
                        if(vis[nrow][ncol] == 0)
                        {
                            vis[nrow][ncol] = 1 ;
                            q.push({nrow,ncol}) ;
                        }
                    }
                }
            }

            dist++ ;
        }

        return mat ;
    }
};