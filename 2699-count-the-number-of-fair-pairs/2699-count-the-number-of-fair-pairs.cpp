class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        
        long long ans = 0;
        for(int i = 0 ; i < nums.size(); i++){
            int l = i+1;
            int r = nums.size() - 1;
            int low = 123456789;
            while(l <= r){
                int mid = (l + r ) / 2;
                if(nums[mid] + nums[i] >= lower){
                    r = mid - 1;
                    low = mid;
                }else{
                    l = mid + 1;
                }
            }
            l = i + 1;
            r = nums.size() - 1;
            int up = 0;
            while(l <= r){
                int mid = (l + r ) / 2;
                if(nums[mid] + nums[i] <= upper){
                    l = mid + 1;
                    up = mid;
                }else{
                    r = mid - 1;
                }
            }
            if(low<=up){
                ans += up - low + 1;
            }
        }
        return ans;
    }
};