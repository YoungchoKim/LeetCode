class Solution {
public:
    int findKthNumber(int n, int k) {
        int result = 1;
        while (k > 1) {
            int count = findKthNumber(result, result + 1, n);
            if (count < k) {
                result++;
                k -= count;
            } else {
                result *= 10;
                k--;
            }
        }
        return result;
    }
    int findKthNumber(long p, long q, long n) {
        int result = 0;
        while (p <= n) {
            result += min(q, n + 1) - p;
            p *= 10;
            q *= 10;
        }
        return result;
    }
};