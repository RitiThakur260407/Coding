class Solution {
public:
    int number(vector<int>& nums, int goal) {
        int n = nums.size();
        int l = 0, r = 0, count = 0, sum = 0;
        while (r < n) {
            sum += nums[r];
            while ((l <= r) && (sum > goal)) {
                sum -= nums[l];
                l++;
            }
            count += (r - l + 1);
            r++;
        }
        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return number(nums, goal) - number(nums, goal - 1);
    }
};