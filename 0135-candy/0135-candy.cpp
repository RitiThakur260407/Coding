class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> curr(n);

        curr[0] = 1;
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                curr[i] = curr[i - 1] + 1;
            } else {
                curr[i] = 1;
            }
        }

        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                curr[i] = max(curr[i], (curr[i + 1] + 1));
            } else {
                curr[i] = max(curr[i], 1);
            }
        }

        return accumulate(curr.begin(), curr.end(), 0);
    }
};