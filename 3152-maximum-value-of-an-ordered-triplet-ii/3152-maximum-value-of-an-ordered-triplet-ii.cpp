class Solution {
public:

    long long maximumTripletValue(vector<int>& nums) {
        long long ans = 0;
        int maxDist = 0;
        vector<int> st;

        for(int i = 0; i < nums.size(); i++){
            if(st.size() >= 2){
                maxDist = max(maxDist, st[0] - st.back());
            }
            ans = max(ans, (long long)maxDist * nums[i]);
            while(!st.empty() && st.back() < nums[i]){
                st.pop_back();
            }
            st.push_back(nums[i]);
        }
        return ans;
    }
};