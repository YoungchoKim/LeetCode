class Solution {
public:
    vector<int> backup;
    void rotate(vector<int>& nums, int k) {
        int N = nums.size();
        int cur = 0;
        k = k % N;
        if (k == 0 ) return;
        int idx = N - k;
        while(idx < N){
            if (idx != cur && cur < N - k)
                backup.push_back(nums[cur]);
            nums[cur++] = nums[idx++];
        }
        
        for(int idx = cur; idx < N - k; idx++){
            backup.push_back(nums[idx]);
        }
        for(int i = 0 ; i < backup.size(); i++){
            nums[cur++] = backup[i];
        }
    }
};