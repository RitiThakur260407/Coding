class Solution {
public:
    int climbStairs(int n) {
        vector<int> steps(n + 2);
        steps[n + 1] = 0;
        steps[n] = 1;

        for (int i = n - 1; i >= 0; i--) {
            steps[i] = steps[i + 1] + steps[i + 2];
        }

        return steps[0];
    }
};