class Solution {
public:
    unordered_map<long long, long long> map;
    long long countBadPairs(vector<int>& nums) {
        int N = nums.size();
        for(int i = 0 ; i < N; i++){
            nums[i] += N - i;
        }
        for(int i = 0 ; i < N; i++){
            map[nums[i]]++;
        }
        long long cnt = 0;
        for(auto iter : map){
            if(iter.second >= 2){
                cnt += ((iter.second) * (iter.second-1)) >> 1;
            }
        }
        return (((long long)N * (N-1)) >> 1) - cnt;
    }
};