class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int prefSum = 0, count = 0;
        unordered_map<int, int> mpp;
        mpp[prefSum]++;

        for (int i = 0; i < n; i++) {
            prefSum += nums[i];
            int left = prefSum - k;
            if (mpp.find(left) != mpp.end()) {
                count += mpp[left];
            }
            mpp[prefSum]++;
        }

        return count;
    }
};