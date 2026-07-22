class Solution {
public:
    bool checkSum(int ind, int target, vector<int>& arr,
                  vector<vector<int>>& dp) {
        if (target == 0)
            return true;

        if (ind == 0)
            return (target == arr[ind]);

        if (dp[ind][target] != -1)
            return dp[ind][target];

        bool pick = false;
        if (target >= arr[ind]) {
            pick = checkSum(ind - 1, target - arr[ind], arr, dp);
        }

        bool notpick = checkSum(ind - 1, target, arr, dp);

        return dp[ind][target] = (pick || notpick);
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int sum = accumulate(nums.begin(), nums.end(), 0);

        if (sum % 2 == 1) {
            return false;
        }

        vector<vector<bool>> dp(n, vector<bool>((sum / 2) + 1, false));

        for (int ind = 0; ind < n; ind++) {
            dp[ind][0] = true;
        }

        if (nums[0] <= sum/2) {
            dp[0][nums[0]] = true;
        }

        for (int ind = 1; ind < n; ind++) {
            for (int target = 0; target <= sum / 2; target++) {
                bool pick = false;
                if (target >= nums[ind]) {
                    pick = dp[ind - 1][target - nums[ind]];
                }

                bool notpick = dp[ind - 1][target];

                dp[ind][target] = pick || notpick;
            }
        }

        return dp[n - 1][sum / 2];
    }
};