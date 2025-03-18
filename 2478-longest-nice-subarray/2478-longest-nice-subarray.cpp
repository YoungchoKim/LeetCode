class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int l = 0;
        int r = 0;
        int prefixSum = 0;
        int ans = 0;
        while(l < nums.size() && r < nums.size()){
            if((prefixSum & nums[r]) == 0){
                prefixSum += nums[r];
                r++;
                ans = max(ans, r - l);
            }else{
                prefixSum -= nums[l];
                l++;
            }
        }
        return ans;
    }
};