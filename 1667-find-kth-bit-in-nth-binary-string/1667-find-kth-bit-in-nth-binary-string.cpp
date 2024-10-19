class Solution {
public:
    char arr[2<<20 + 1] = {0};
    char findKthBit(int n, int k) {
        int size = 1;
        for(int i = 0 ; i < n ; i++){
            int s = size;
            if (k <= s) return arr[k-1] + '0';
            arr[s++] = 1;
            for(int i = size-1; i >= 0; i--){
                arr[s++] = arr[i] ^ 1;
            }
            size = s;
        }
        return arr[k - 1] + '0';
    }
};