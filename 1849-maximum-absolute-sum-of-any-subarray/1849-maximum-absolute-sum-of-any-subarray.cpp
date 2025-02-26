class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int r = 0;
        int l = 0;
        int plusMax = 0;
        int prefixSum = 0;
        for(int num : nums){
            prefixSum += num;
            if(prefixSum < 0) prefixSum = 0;
            plusMax = max(plusMax, prefixSum);
        }

        int minusMin = 0;
        prefixSum = 0;
        for(int num:nums){
            prefixSum += num;
            if(prefixSum > 0) prefixSum = 0;
            minusMin = min(minusMin, prefixSum);
        }
        return plusMax > abs(minusMin) ? plusMax : abs(minusMin);
    }
};