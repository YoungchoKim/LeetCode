class Solution {
public:
    vector<int> v;
    long long countSubarrays(vector<int>& nums, int k) {
        int maxV = 0;
        for(int i = 0 ; i < nums.size(); i++){
            if(maxV < nums[i]){
                maxV = nums[i];
                v.clear();
                v.push_back(i);
            } else if (maxV == nums[i]){
                v.push_back(i);
            }
        }
        v.push_back(nums.size());
        
        long long ans = 0;
        for(int i = k-1; i < v.size()-1; i++){
            long long r = v[i];
            long long l = v[i - k+1];
            ans += (l+1) * (v[i+1]-r);
        }
        return ans;
    }
};