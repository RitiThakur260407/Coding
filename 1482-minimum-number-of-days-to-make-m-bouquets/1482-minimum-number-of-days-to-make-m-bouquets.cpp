class Solution {
public:
    int numberOfBouqets(vector<int>& bloomDay, int k, int days) {
        int count = 0, number = 0;
        for (int i = 0; i < bloomDay.size(); i++) {
            if (bloomDay[i] <= days) {
                count++;
            } else {
                count = 0;
            }

            if (count == k) {
                number++;
                count = 0;
            }
        }
        return number;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        int low = *min_element(bloomDay.begin(), bloomDay.end()),
            high = *max_element(bloomDay.begin(), bloomDay.end()), days = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int bouquets = numberOfBouqets(bloomDay, k, mid);

            if (bouquets >= m) {
                days = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return days;
    }
};