class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        if(nums[0] < k) return -1;
        int cnt = 0;
        int cur = nums[0];
        if(cur != k) cnt++;
        for(int i = 1; i < nums.size(); i++){
            if(cur != nums[i]){
                cnt++;
                cur = nums[i];
            }
        }
        return cnt;
    }
};