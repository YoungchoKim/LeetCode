class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        bool flag = nums[0] & 1;
        for(int i = 1; i < nums.size(); i++){
            if(flag ^ (nums[i] & 1)){
                flag ^= 1;
            } else{
                return false;
            }
        }
        return true;
    }
};