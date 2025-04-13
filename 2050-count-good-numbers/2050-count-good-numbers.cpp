struct powRet{
    long long ret;
    long long n;
};
class Solution {
public:
    const int MOD = 1000000007;
    powRet powpow(long long n, long long num){
        powRet ret;
        long long pow = num;
        long long nn = 1;
        long long beforePow = pow;
        long long beforenn = nn;
        while(nn <= n){
            nn *= 2;
            pow *= pow;
            pow %= MOD;
            if(nn > n) break;
            beforePow = pow;
            beforenn = nn;
        }
        ret.ret = beforePow;
        ret.n = beforenn;
        return ret;
    }
    int countGoodNumbers(long long n) {
        long long ans= 1;
        long long a = (n + 1)/2;
        long long b = n - a;
        while(a){
            powRet ret = powpow(a, 5);
            ans *= ret.ret;
            ans %= MOD;
            a -= ret.n;
        }
        while(b){
            powRet ret = powpow(b, 4);
            ans *= ret.ret;
            ans %= MOD;
            b -= ret.n;
        }
        return ans;
    }
};