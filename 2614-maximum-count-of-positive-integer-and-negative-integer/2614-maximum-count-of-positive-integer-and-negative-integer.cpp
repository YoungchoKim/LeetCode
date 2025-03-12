class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int minus = 0;
        int plus = 0;
        for(int i = 0 ; i < nums.size(); i++){
            if(nums[i] < 0){
                minus++;
            }else if (nums[i] > 0){
                plus++;
            }
        }
        return max(minus, plus);
    }
};