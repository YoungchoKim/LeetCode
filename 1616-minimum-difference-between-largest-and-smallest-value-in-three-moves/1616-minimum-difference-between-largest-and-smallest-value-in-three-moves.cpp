int abs(int x){
    return x < 0 ? -x : x;
}
class Solution {
public:
    int dfs(vector<int>&nums, int depth, int l, int r){
        if (depth == 3){
            return nums[r] - nums[l];
        }
        int res = dfs(nums, depth+1, l+1, r);
        res = min(res, dfs(nums, depth+1, l, r-1));
        return res;
    }
    int minDifference(vector<int>& nums) {
        if (nums.size() <= 3) return 0;
        sort(nums.begin(), nums.end());
        int l = 0;
        int r = nums.size() - 1;
        return dfs(nums, 0, l, r);
    }
};