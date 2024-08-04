#define MOD 1000000007
class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> arr;
        long long sum = 0;
        for(int i = 0 ; i < nums.size(); i++){
            sum += nums[i];
            sum %= MOD;
            arr.push_back(sum);
            long long sum2 = 0;
            for(int j = i+1 ; j < nums.size(); j++){
                sum2 += nums[j];
                sum2 %= MOD;
                arr.push_back(sum2);
            }
        }
        sort(arr.begin(), arr.end());
        long long sum3 = 0;
        for(int i = left -1; i < right; i++){
            sum3 += arr[i];
            sum3 %= MOD;
        }
        return sum3;
    }
};