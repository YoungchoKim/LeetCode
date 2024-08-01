class Solution {
public:
    int dp[1001];
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int N = books.size();
        for(int i = 1; i <= N; i++){
            int width = books[i-1][0];
            int height = books[i-1][1];
            dp[i] = dp[i-1] + height;
            for(int j = i -1; j > 0; j--){
                height = max(height, books[j-1][1]);
                width += books[j-1][0];
                if (width > shelfWidth) break;
                dp[i] = min(dp[j-1] + height, dp[i]);
            }
        }
        return dp[N];
    }
};