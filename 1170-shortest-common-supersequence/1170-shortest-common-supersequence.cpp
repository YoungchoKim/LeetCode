class Solution {
public:
    int dp[1001][1001];
    string shortestCommonSupersequence(string str1, string str2) {
        int cnt1 = 0;
        for(int i = 0 ; i < str1.size(); i++){
            for(int j = 0 ; j < str2.size(); j++){
                if(str1[i] == str2[j]){
                    dp[i+1][j+1] = dp[i][j] + 1;
                } else{
                    dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
                }
            }
        }
        string s = "";
        int i = str1.size();
        int j = str2.size();
        while(i > 0 && j > 0){
            if(dp[i][j] == dp[i][j-1]){
                j--;
            } else if(dp[i][j] == dp[i-1][j]){
                i--;
            } else{
                s += str1[i-1];
                i--;
                j--;
            }
        }
        reverse(s.begin(), s.end());
        string res = "";
        int idx1 = 0;
        int idx2 = 0;
        for(int i = 0; i < s.size(); i++){
            while(str1[idx1] != s[i]){
                res += str1[idx1];
                idx1++;
            }
            while(str2[idx2] != s[i]){
                res += str2[idx2];
                idx2++;
            }
            res += s[i];
            idx1++;
            idx2++;
        }
        while(idx1 < str1.size()){
            res += str1[idx1++];
        }
        while(idx2 < str2.size()){
            res += str2[idx2++];
        }

        return res;
    }
};