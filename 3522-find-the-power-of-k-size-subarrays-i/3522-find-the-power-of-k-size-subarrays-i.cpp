class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> ans;
        int acd_cnt = 1;
        int cmp_num = nums[0];
        for(int i = 1 ; i < k ;i++){
            if(cmp_num + 1 == nums[i]){
                acd_cnt++;
            } else {
                acd_cnt = 1;
            }
            cmp_num = nums[i];
        }
        if(acd_cnt == k){
            ans.push_back(cmp_num);
        } else {
            ans.push_back(-1);
        }
        for(int i = k ; i < nums.size(); i++){
            if(cmp_num + 1 == nums[i]){
                acd_cnt++;
            } else {
                acd_cnt = 1;
            }
            if(acd_cnt >= k){
                ans.push_back(nums[i]);
            } else {
                ans.push_back(-1);
            }
            cmp_num = nums[i];
        }
        return ans;
    }
};