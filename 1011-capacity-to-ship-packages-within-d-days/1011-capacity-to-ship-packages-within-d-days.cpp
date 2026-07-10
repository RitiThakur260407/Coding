class Solution {
public:
    int numberOfDays(vector<int>& weights, int capacity) {
        int total = 0, days = 1;
        for (int i = 0; i < weights.size(); i++) {
            if ((total + weights[i]) <= capacity) {
                total += weights[i];
            } else {
                days++;
                total = weights[i];
            }
        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        long long low = *max_element(weights.begin(), weights.end());
        long long high = accumulate(weights.begin(), weights.end(), 0);
        long long capacity = high;
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            long long time = numberOfDays(weights, mid);
            if (time <= days) {
                capacity = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return capacity;
    }
};