class Solution {
public:
    long long TimeTaken(vector<int>& piles, long long speed) {
        long long total_time = 0;
        for (int i = 0; i < piles.size(); i++) {
            total_time += (piles[i] + speed - 1) / speed;
        }
        return total_time;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        long long low = 1, high = *max_element(piles.begin(), piles.end()), k = high;
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            long long total_time = TimeTaken(piles, mid);

            if (total_time <= h) {
                k = mid;
                high = mid - 1;
                ;
            } else {
                low = mid + 1;
            }
        }
        return (int)k;
    }
};