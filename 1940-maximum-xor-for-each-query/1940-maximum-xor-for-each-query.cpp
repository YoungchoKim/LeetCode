class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int max_num = (1 << maximumBit) - 1;
        vector<int> res;
        int acc = 0;
        for(int i = 0 ; i < nums.size(); i++) {
            acc ^= nums[i];
        }

        for(int i = nums.size()-1; i>= 0; i--) {
            res.push_back(acc ^ max_num);
            acc ^= nums[i];
        }
        return res;
    }
};