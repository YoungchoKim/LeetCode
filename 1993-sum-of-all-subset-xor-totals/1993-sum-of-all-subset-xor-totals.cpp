class Solution {
public:
    int ans = 0;
    void go(int cur, int sum, vector<int>& nums){
        if(cur >= nums.size()) {
            ans += sum;
            return;
        }
        go(cur + 1, sum ^ nums[cur], nums );
        go(cur + 1, sum, nums );
    }
    int subsetXORSum(vector<int>& nums) {
        go(0, 0, nums);
        return ans;
    }
};