class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size() ;
        int n = matrix[0].size() ;
        vector<int> markRow(m,0) , markCol(n,0) ;
        for(int i = 0 ; i < m ; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                if(matrix[i][j] == 0)
                {
                    markRow[i] = 1 ;
                    markCol[j] = 1 ;
                }
            }
        }

        for(int i = 0 ; i < m ; i++)
        {
            if(markRow[i] == 1)
            {
                for(int j = 0 ; j < n ; j++)
                {
                    matrix[i][j] = 0 ;
                }
            }
        }

        for(int j = 0 ; j < n ; j++)
        {
            if(markCol[j] == 1)
            {
                for(int i = 0 ; i < m ; i++)
                {
                    matrix[i][j] = 0 ;
                }
            }
        }
    }
};