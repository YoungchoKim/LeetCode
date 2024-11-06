class Solution {
public:
    int getOneCnt(int num){
        int cnt = 0;
        while(num){
            cnt++;
            num &= num-1;
        }
        return cnt;
    }
    vector<int> arr;
    bool canSortArray(vector<int>& nums) {
        int beforeCnt = getOneCnt(nums[0]);
        int beforeMax = 0;
        int maxNum = nums[0];
        for(int i = 1 ; i < nums.size(); i++){
            int cnt = getOneCnt(nums[i]);
            if( cnt != beforeCnt){
                if(maxNum > nums[i]) return false;
                beforeMax = maxNum;
                maxNum = nums[i];
                beforeCnt = cnt;
                continue;
            }
            if(beforeMax > nums[i]) return false;
            if(maxNum < nums[i]){
                maxNum = nums[i];
            }
        }

        return true;
    }
};