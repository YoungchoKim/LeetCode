class Solution {
public:
    long long coloredCells(int n) {
        int i = 1;
        int odd = (i - 1) * 2 + 1;
        long long sum = 0;
        for( ; i < n; i++){
            sum += odd*2;
            odd = i * 2 + 1;
        }
        return sum + odd;
    }
};