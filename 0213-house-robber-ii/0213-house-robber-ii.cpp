class Solution {
public:
    int money(int ind, int end, vector<int>& nums, vector<int>& dp) {
        if (ind >= end) {
            return 0;
        }

        if (dp[ind] != -1)
            return dp[ind];

        int pick = 0, notpick = 0;

        pick = nums[ind] + money(ind + 2, end, nums, dp);
        notpick = money(ind + 1, end, nums, dp);

        return dp[ind] = max(pick, notpick);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1)
            return nums[0];

        vector<int> dp1(n,-1), dp2(n,-1);
        return max(money(0, n - 1, nums, dp1), money(1, n, nums, dp2));
    }
};