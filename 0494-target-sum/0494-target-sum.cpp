class Solution {
public:
    int memo[20][2001];
    int findTargetSumWays(vector<int>& nums, int target, int cur=0, int sum=0) {
        if(cur == 0){
            memset(memo, -1, sizeof(memo));
        }
        if(cur == nums.size()){
            if (sum == target){
                return 1;
            }
            return 0;
        }
        if(memo[cur][sum+1000] != -1) return memo[cur][sum+1000];
        int res = 0;
        res += findTargetSumWays(nums, target, cur+1, sum + nums[cur]);
        res += findTargetSumWays(nums, target, cur+1, sum - nums[cur]);
        return memo[cur][sum+1000] = res;
    }
};