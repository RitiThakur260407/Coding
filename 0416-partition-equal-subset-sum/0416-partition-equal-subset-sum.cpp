class Solution {
public:
    bool checkSum(int ind, int target, vector<int>& arr , vector<vector<int>>& dp)
	{
		if (target == 0)
			return true ;
		
		if (ind == 0)
			return (target == arr[ind]) ;
			
		if(dp[ind][target] != -1)
		return dp[ind][target] ;
		
		bool pick = false ;
		if (target >= arr[ind])
			{
			pick = checkSum(ind - 1, target - arr[ind], arr,dp) ;
		}
		
		bool notpick = checkSum(ind - 1, target, arr,dp) ;
		
		return dp[ind][target] = (pick || notpick) ;
	}
    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int sum = accumulate(nums.begin(), nums.end(), 0);

        if (sum % 2 == 1) {
            return false;
        }

        vector<vector<int>> dp(n,vector<int>((sum/2)+1,-1)) ;

        return checkSum(n - 1, sum / 2, nums,dp);
    }
};