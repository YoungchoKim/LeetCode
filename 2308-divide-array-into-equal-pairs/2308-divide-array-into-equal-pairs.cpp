class Solution {
public:
    int cnt[501] = {0};
    bool divideArray(vector<int>& nums) {
        for(int n : nums){
            cnt[n]++;
        }
        for(int i = 1; i <= 500; i++){
            if(cnt[i] &1){
                return false;
            }
        }
        return true;
    }
};