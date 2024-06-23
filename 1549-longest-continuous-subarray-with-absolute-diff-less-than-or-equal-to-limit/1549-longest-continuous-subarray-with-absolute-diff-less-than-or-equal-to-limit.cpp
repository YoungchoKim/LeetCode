class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int l = 0;
        int r = 0;
        multiset<int> multi;
        int N = nums.size();
        int ans = 0;
        
        multi.insert(nums[0]);
        while(r < N){
            int last = *(multi.rbegin());
            int first = *(multi.begin());
            if (abs(last - first) <= limit){
                ans = max(ans, r-l+1);
                r++;
                if (r < N){
                    multi.insert(nums[r]);
                }
            } else{
                multi.erase(multi.find(nums[l]));
                l++;
            }
        }
        return ans;
    }
};