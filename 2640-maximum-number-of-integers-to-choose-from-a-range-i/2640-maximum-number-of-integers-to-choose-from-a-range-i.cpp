class Solution {
public:
    vector<int> nums;
    bool ban[10001];
    int maxCount(vector<int>& banned, int n, int maxSum) {
        for(int i = 0 ; i < banned.size(); i++){
            ban[banned[i]] = true;
        }
        for(int i = 1; i <= n; i++){
            if(ban[i]) continue;
            nums.push_back(i);
        }
        int sum = 0;
        int ans = 0;
        for(int i = 0 ; i < nums.size(); i++){
            sum += nums[i];
            if(sum > maxSum) break;
            ans++;
        }
        return ans;
    }
};