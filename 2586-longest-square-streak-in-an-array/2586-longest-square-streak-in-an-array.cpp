class Solution {
public:
    bool isNum[100001] = {false};
    int longestSquareStreak(vector<int>& nums) {
        for(int i = 0 ; i < nums.size(); i++){
            isNum[nums[i]] = true;
        }
        int ans = -1;
        for(int i = 0 ; i < 100001; i++){
            if (!isNum[i]) continue;
            long long j = i;
            int cnt = 0;
            while(j <= 100000 && isNum[j]){
                cnt++;
                j = j*j;
            }
            if(cnt >= 2)
                ans = max(ans, cnt);
        }
        return ans;
    }
};