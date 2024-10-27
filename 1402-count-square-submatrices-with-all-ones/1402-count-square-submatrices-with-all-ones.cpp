class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int dp[301][301] = {0};
        int res = 0;
        for(int i = 0 ; i < matrix.size(); i++){
            for(int j = 0 ; j < matrix[i].size();j++){
                if(matrix[i][j] == 0){
                    continue;
                }
                if(i-1 < 0 || j-1 < 0){
                    dp[i][j] = matrix[i][j];
                    res += dp[i][j];
                    continue;
                }
                dp[i][j] = min(dp[i-1][j],min(dp[i-1][j-1], dp[i][j-1])) + 1;
                res += dp[i][j];
            }
        }
        
        return res;
    }
};