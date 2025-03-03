class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> less;
        vector<int> equal;
        vector<int> greater;
        for(int i = 0 ; i < nums.size(); i++){
            if(nums[i] < pivot){
                less.push_back(nums[i]);
            } else if(nums[i] > pivot){
                greater.push_back(nums[i]);
            } else{
                equal.push_back(nums[i]);
            }
        }
        vector<int> ans;
        ans.insert(ans.end(), less.begin(), less.end());
        ans.insert(ans.end(), equal.begin(), equal.end());
        ans.insert(ans.end(), greater.begin(), greater.end());
        return ans;
    }
};