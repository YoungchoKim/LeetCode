class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<bool> ans;
        vector<int> memo;
        memo.push_back(1);
        for(int i = 1 ; i < nums.size(); i++){
            int num = memo.back();
            if(nums[i] %2 == nums[i-1] %2){
                memo.push_back(num);
            } else{
                memo.push_back(num+1);
            }
        }
        for(int i =  0; i < queries.size(); i++){
            int a = queries[i][0];
            int b = queries[i][1];
            if(b- a == memo[b] - memo[a]){
                ans.push_back(true);
            } else {
                ans.push_back(false);
            }
        }
        return ans;
    }
};