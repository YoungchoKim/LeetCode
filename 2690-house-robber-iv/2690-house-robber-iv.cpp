class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int l = 1;
        int r = 1000000000;
        int ans = 0;
        while(l <= r){
            // int mid = l + ((r - l) >> 1);
            int mid = (l + r)/2;
            int cnt = 0;
            for(int i = 0 ; i < nums.size(); i++){
                if(nums[i] <= mid){
                    cnt++;
                    i++;
                }
            }
            if(cnt >= k){
                r = mid - 1;
                ans = mid;
            } else{
                l = mid + 1;

            }
        }
        return ans;
    }
};