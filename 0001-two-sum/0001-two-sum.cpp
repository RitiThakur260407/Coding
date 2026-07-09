class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size() ;
        vector<int> ans;
        unordered_map<int, int> mpp;
        for (int i = 0; i < n; i++) {
            int left = target - nums[i];
            if (mpp.find(left) != mpp.end()) {
                ans = {mpp[left], i};
                break ;
            }
            mpp[nums[i]] = i ;
        }
        return ans ;
    }
};