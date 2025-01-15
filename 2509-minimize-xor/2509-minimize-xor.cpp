class Solution {
public:
    int bitCount(int n){
        int cnt = 0;
        while(n){
            cnt++;
            n &= n-1;
        }
        return cnt;
    }
    int minimizeXor(int num1, int num2) {
        int bit1 = bitCount(num1);
        int bit2 = bitCount(num2);
        int x = num1;
        int diff = bit2 - bit1;
        if(diff == 0) return num1;
        else if(diff > 0){
            long long offset = 1;
            while(diff){
                if((offset & x) == 0){
                    diff--;
                }
                x |= offset;
                offset <<= 1;
            }
        } else{
            diff = -diff;
            while(diff--){
                x &= x - 1;
            }
        }
        return x;
    }
};