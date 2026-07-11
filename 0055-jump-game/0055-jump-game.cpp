class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxDist = 0;
        for (int i = 0; i < n; i++) {
            if (i > maxDist) {
                return false;
            }
            maxDist = max(maxDist, (nums[i] + i));
            if (maxDist >= n - 1) {
                return true;
            }
        }
        return true;
    }
};