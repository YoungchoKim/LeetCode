class Solution {
public:
    long long pSum[100000];
    int waysToSplitArray(vector<int>& nums) {
        pSum[0] = nums[0];
        for(int i = 1 ; i < nums.size(); i++){
            pSum[i] = pSum[i-1] + nums[i];
        }
        int ans = 0;
        int last = nums.size() - 1;
        for(int i = 0; i < last; i++){
            if(pSum[i] >= pSum[last] - pSum[i]){
                ans++;
            }
        }
        return ans;
    }
};