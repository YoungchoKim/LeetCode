class Solution {
public:
    int passThePillow(int n, int time) {
        int a = time / (n-1);
        if(a&1){
            return n - time % (n-1);
        } else{
            return 1 + time % (n-1);
        }
    }
};