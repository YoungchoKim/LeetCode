#define MOD 1000000007
class Solution {
public:
    int memo[1001];
    int numTilings(int n) {
        memo[0] = 1;
        memo[1] = 1;
        memo[2] = 2;
        memo[3] = 5;
        for(int i = 4; i <= n; i++){
            memo[i] = (memo[i-1] + memo[i-2])%MOD;
            for(int j = i - 3; j >= 0; j--){
                memo[i] += (memo[j]*2)%MOD;
                memo[i] %= MOD;
            }
        }
        return memo[n];
    }
};