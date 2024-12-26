class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target, int cur=0, int sum=0) {
        if(cur == nums.size()){
            if (sum == target){
                return 1;
            }
            return 0;
        }
        int res = 0;
        res += findTargetSumWays(nums, target, cur+1, sum + nums[cur]);
        res += findTargetSumWays(nums, target, cur+1, sum - nums[cur]);
        return res;
    }
};