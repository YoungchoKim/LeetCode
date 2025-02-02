class Solution {
public:
    bool check(vector<int>& nums) {
        int N = nums.size();
        int minIdx = 0;
        int minValue = 101;
        for(int i = 0; i <N; i++){
            if(minValue> nums[i]){
                minIdx = i;
                minValue = nums[i];
            }
        }
        int idx = N - 1;
        while(idx >= 0 && minIdx != N-1 && nums[minIdx] == nums[idx]){
            idx--;
        }
        if(idx != N-1){
            minIdx = idx + 1;
        }
        int beforeVal = nums[minIdx];
        minIdx = (minIdx + 1) %N;
        int n = N;
        n--;
        while(n--){
            if(beforeVal > nums[minIdx]){
                return false;
            }
            beforeVal = nums[minIdx];
            minIdx = (minIdx + 1) %N;
        }
        return true;
    }
};