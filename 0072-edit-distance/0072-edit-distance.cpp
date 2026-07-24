class Solution {
public:
    int dist(int ind1, int ind2, string& word1, string& word2 , vector<vector<int>>& dp) {
        if (ind1 < 0) {
            return (ind2 + 1);
        }

        if (ind2 < 0) {
            return (ind1 + 1);
        }

        if(dp[ind1][ind2] != -1)
        return dp[ind1][ind2] ;

        if(word1[ind1] == word2[ind2])
        return dp[ind1][ind2] = dist(ind1-1,ind2-1,word1,word2,dp) ;

        int ins = dist(ind1, ind2 - 1, word1, word2,dp);
        int del = dist(ind1 - 1, ind2, word1, word2,dp);
        int replace = dist(ind1 - 1, ind2 - 1, word1, word2,dp);

        return dp[ind1][ind2] = 1 + min(ins, min(del, replace));
    }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n,vector<int>(m,-1)) ;

        return dist(n - 1, m - 1, word1, word2,dp);
    }
};