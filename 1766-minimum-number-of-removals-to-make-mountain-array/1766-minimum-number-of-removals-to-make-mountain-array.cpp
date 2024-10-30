class Solution {
public:
    int dp1[1001];
    int dp2[1001];
    int minimumMountainRemovals(vector<int>& nums) {
        int N = nums.size();
        dp1[N - 1] = 1;
        for(int i = N-2; i>= 0; i--){
            dp1[i] = 1;
            for(int j = i + 1; j < N; j++){
                if(nums[j]< nums[i]){
                    dp1[i] = max(dp1[i], dp1[j] + 1);
                }
            }
        }

        dp2[0] = 1;
        for(int i = 1 ; i < nums.size(); i++){
            dp2[i] = 1;
            for(int j = i -1; j >= 0; j--){
                if(nums[j]< nums[i]){
                    dp2[i] = max(dp2[i], dp2[j] + 1);
                }
            }
        }
        int res = 0;
        for(int i = 1 ; i< N-1; i++){
            if(nums[i-1] >= nums[i]) continue;
            int j_max = 0;
            bool success = false;
            for(int j = i + 1; j < N; j++){
                if(nums[i] <= nums[j]){
                    continue;
                }
                success = true;
                j_max = max(j_max, dp1[j]);
            }
            if (success)
                res = max(res, j_max + dp2[i]);
        }
        return N -res;
    }
};