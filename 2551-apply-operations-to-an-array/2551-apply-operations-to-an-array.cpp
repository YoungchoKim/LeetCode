class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int idx = 0;
        vector<int> ans;
        while(idx < nums.size()){
            while(idx < nums.size() && nums[idx] == 0){
                idx++;
            }
            if(idx >= nums.size()) break;
            int num = nums[idx];
            if((idx + 1) < nums.size() && (nums[idx] == nums[idx+1])){
                num <<= 1;
                idx++;
            }
            ans.push_back(num);
            idx++;
        }
        int ansSize = ans.size();
        while(ansSize < nums.size()){
            ans.push_back(0);
            ansSize++;
        }
        return ans;
    }
};