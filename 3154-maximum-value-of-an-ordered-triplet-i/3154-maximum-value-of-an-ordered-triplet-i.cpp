class Solution {
public:
    long long ans = 0;
    void combi(vector<int>&nums, int cur, int depth, vector<long long>& selected){
        if(depth == 3){
            ans = max(ans, (selected[0] - selected[1])*selected[2]);
            return;
        }
        for(int i = cur + 1; i < nums.size(); i++){
            selected.push_back(nums[i]);
            combi(nums, i, depth + 1, selected);
            selected.pop_back();
        }
    }
    long long maximumTripletValue(vector<int>& nums) {
        vector<long long> selected;
        combi(nums,-1, 0, selected);
        return ans;
    }
};