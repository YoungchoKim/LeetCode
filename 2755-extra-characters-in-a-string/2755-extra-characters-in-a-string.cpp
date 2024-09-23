class Solution {
public:
    int dp[51];
    int go(string & s, vector<string>& dict, int i){
        if(i == s.size()) return 0;

        if (dp[i] == -1){
            dp[i] = 1 + go(s, dict, i+1);
            for(auto &w: dict){
                if(s.compare(i, w.size(), w) == 0){
                    dp[i] = min(dp[i], go(s, dict, i+w.size()));
                }
            }
        }
        return dp[i];

    }
    int minExtraChar(string s, vector<string>& dictionary) {
        memset(dp, -1, sizeof(dp));
        return go(s, dictionary, 0);
    }
};