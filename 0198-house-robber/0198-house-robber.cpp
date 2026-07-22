class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int ahead = 0, ahead1 = 0;

        for (int i = n - 1; i >= 0; i--) {
            int pick = nums[i] + ahead1;
            int notpick = ahead;

            int curr = max(pick, notpick);
            ahead1 = ahead;
            ahead = curr;
        }

        return ahead;
    }
};