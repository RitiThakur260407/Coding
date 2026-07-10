class Solution {
public:
    long long SubarraySum(vector<int>& nums, long long sum) {
        long long total = 0, number = 1;
        for (int i = 0; i < nums.size(); i++) {
            if ((total + nums[i]) <= sum) {
                total += nums[i];
            } else {
                number++;
                total = nums[i];
            }
        }
        return number;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        long long low = *max_element(nums.begin(), nums.end());
        long long high = accumulate(nums.begin(), nums.end(), 0);
        long long sum;
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            long long number = SubarraySum(nums, mid);

            if (number <= k) {
                sum = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return sum;
    }
};