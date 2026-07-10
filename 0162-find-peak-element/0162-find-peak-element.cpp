class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long prev = (mid >= 1) ? nums[mid - 1] : LLONG_MIN;
            long long next = (mid < n - 1) ? nums[mid + 1] : LLONG_MIN;

            if ((nums[mid] > prev) && (nums[mid] > next)) {
                return mid;
            } else {
                if (nums[mid] < next) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
};