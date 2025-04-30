class Solution {
public:
    int getDigitNum(int num){
        int cnt = 0;
        while(num){
            num/=10;
            cnt++;
        }
        return cnt;
    }
    int findNumbers(vector<int>& nums) {
        int ans = 0;
        for(int num : nums){
            if(getDigitNum(num) % 2){
                continue;
            }
            ans++;
        }
        return ans;
    }
};