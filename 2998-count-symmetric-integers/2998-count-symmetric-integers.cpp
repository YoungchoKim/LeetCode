class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int ans = 0;
        for(int i = low; i <= high; i++){
            if(i / 1000){
                int a = i / 1000;
                int b = (i % 1000) / 100;
                int c = (i % 100) / 10;
                int d = (i % 10);
                if((a + b) == (c + d)){
                    ans++;
                }
            } else if( ((i/10) > 0) && ((i/10) < 10)){
                int a = i/10;
                int b = i%10;
                if(a == b) ans++;
            }
        }
        return ans;
    }
};