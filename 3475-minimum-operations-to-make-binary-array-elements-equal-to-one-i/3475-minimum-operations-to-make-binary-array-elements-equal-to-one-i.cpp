class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0;
        for(int i = 0 ; i < nums.size(); i++){
            if(nums[i] == 0){
                for(int j = i; j < i + 3; j++){
                    if(j >= nums.size()) return -1;
                    nums[j] ^= 1;
                }
                ans++;
            }
        }
        return ans;
    }
};