#define MOD 1000000007
class Solution {
public:
    int memo[100001];
    long long getCnt(int length, int zero, int one){
        if(length < 0) return 0;
        if(length == 0){
            return 1;
        }
        if(memo[length] != -1) return memo[length];
        long long ret = 0;
        ret += getCnt(length - zero, zero, one);
        ret %= MOD;
        ret += getCnt(length - one , zero, one);
        ret %= MOD;
        return memo[length] = ret;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        memset(memo, -1, sizeof(memo));
        long long ans = 0;
        for(int i = low; i <= high; i++){
            ans += getCnt(i, zero, one);
            ans %= MOD;
        }
        return ans;
    }
};