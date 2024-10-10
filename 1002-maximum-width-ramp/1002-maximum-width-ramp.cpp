class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        int ans = 0;
        while(l <= r){
            int win_size = (l + r) / 2;
            bool success = false;
            int minValue = 5*10000;
            for(int i = 0; i < nums.size()- win_size; i++){
                minValue = min(minValue, nums[i]);
                if(minValue <= nums[i+win_size]){
                    success = true;
                }
            }
            if(success){
                l = win_size + 1;
                ans = win_size;
            } else {
                r = win_size - 1;
            }

        }
        return ans;
    }
};