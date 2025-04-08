class Solution {
public:
    int numberCnt[101];
    int minimumOperations(vector<int>& nums) {
        int lastIdx = -1;
        for(int i = nums.size() - 1 ; i >= 0 ; i--){
            numberCnt[nums[i]]++;
            if(numberCnt[nums[i]] >= 2){
                lastIdx = i;
                break;
            }
        }
        if(lastIdx == -1) return 0;
        return lastIdx / 3 + 1;
    }
};