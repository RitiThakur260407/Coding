class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == divisor) {
            return 1;
        }

        bool sign = true;
        if ((divisor < 0) && (dividend >= 0)) {
            sign = false;
        }
        if ((divisor > 0) && (dividend < 0)) {
            sign = false;
        }

        long long D = llabs((long long)dividend);
        long long d = llabs((long long)divisor);
        long long quotient = 0;

        while (D >= d) {
            int count = 0;
            while (d << (count + 1) <= D) {
                count++;
            }
            quotient += (1LL << count);
            D = D - d * (1LL << count);
        }

        if (quotient == 1LL << 31) {
            if (sign == true) {
                return INT_MAX;
            } else {
                return INT_MIN;
            }
        }
        if (sign == false) {
            quotient = -quotient;
        }
        return quotient;
    }
};