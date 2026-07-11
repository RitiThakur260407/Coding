class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int jumps = 0, l = 0, r = 0;
        while (r < n - 1) {
            int maxDist = 0;
            for (int i = l; i <= r; i++) {
                maxDist = max(maxDist, (nums[i] + i));
            }
            l = r + 1;
            r = maxDist;
            jumps++;
        }
        return jumps;
    }
};