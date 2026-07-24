class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<unsigned int>> dp(n+1, vector<unsigned int>(m+1));
        for(int ind2 = 0 ; ind2 <= m ; ind2++)
        {
            dp[0][ind2] = 0 ;
        }

        for(int ind1 = 0 ; ind1 <= n ; ind1++)
        {
            dp[ind1][0] = 1 ;
        }

        for(int ind1 = 1 ; ind1 <= n ; ind1++)
        {
            for(int ind2 = 1 ; ind2 <= m ;ind2++)
            {
                if(s[ind1-1] == t[ind2-1])
                {
                    unsigned int take = dp[ind1-1][ind2-1] ;
                    unsigned int nottake = dp[ind1-1][ind2] ;

                    dp[ind1][ind2] = take + nottake ;
                }
                else
                {
                    dp[ind1][ind2] = dp[ind1-1][ind2] ;
                }
            }
        }

        return dp[n][m];
    }
};