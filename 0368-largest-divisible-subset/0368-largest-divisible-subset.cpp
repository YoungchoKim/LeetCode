class Solution {
public:
    int dp[1001];
    int prev_idx[1001];
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        // dp
        sort(nums.begin(), nums.end());
        for(int i = 0 ; i < nums.size(); i++){
            dp[i] = 1;
            prev_idx[i] = -1;
        }
        for(int i = 0 ; i < nums.size(); i++){
            for(int j = i - 1 ; j >= 0; j--){
                if((dp[j]+1) > dp[i] && (nums[i] % nums[j]) == 0){
                    dp[i] = dp[j] + 1;
                    prev_idx[i] = j;
                }
            }
        }
        int max = 0;
        int idx = 0;
        for(int i = 0; i < nums.size(); i++){
            if(max < dp[i]){
                max = dp[i];
                idx = i;
            }
        }
        vector<int> ans;
        while(idx != -1){
            ans.push_back(nums[idx]);
            idx = prev_idx[idx];
        }
        return ans;
    }
};