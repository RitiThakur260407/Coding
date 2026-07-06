class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for (int bitInd = 0; bitInd < 32; bitInd++) {
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                if (nums[i] & (1 << bitInd)) {
                    cnt++;
                }
            }
            if (cnt % 3 == 1) {
                ans = ans | (1 << bitInd);
            }
        }
        return ans;
    }
};