class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int l = 0;
        int r = 0;
        int ans = 1;
        while(r < nums.size()){
            if(nums[r] - k <= nums[l] + k){
                r++;
                ans = max(ans, r - l);
            } else{
                l++;
            }
        }
        
        
        return ans;
    }
};