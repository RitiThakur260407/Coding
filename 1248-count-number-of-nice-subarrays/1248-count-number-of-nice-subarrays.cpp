class Solution {
public:
    int number(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0, r = 0, odd = 0, count = 0;

        while (r < n) {
            if (nums[r] % 2 == 1) {
                odd++;
            }
            while ((odd > k)) {
                if (nums[l] % 2 == 1) {
                    odd--;
                }
                l++;
            }
            count += (r - l + 1);
            r++ ;
        }
        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return number(nums, k) - number(nums, k - 1);
    }
};