class Solution {
public:
    
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1));

        for(int ind = 0 ; ind < n ; ind++)
        {
            dp[ind][0] = 0 ;
        }

        for(int target = 0 ; target <= amount ; target++)
        {
            if(target%coins[0] == 0)
            {
                dp[0][target] = target/coins[0] ;
            }
            else
            {
                dp[0][target] = 1e9 ;
            }
        }

        for(int ind = 1 ; ind < n ; ind++)
        {
            for(int target = 0 ; target <= amount ; target++)
            {
                int pick = 1e9 ;
                if(target >= coins[ind])
                {
                    pick = 1 + dp[ind][target-coins[ind]] ;
                }
                int notpick = dp[ind-1][target] ;

                dp[ind][target] = min(pick,notpick) ;
            }
        }

        int total = dp[n-1][amount];

        if (total >= 1e9)
            return -1;

        return total;
    }
};