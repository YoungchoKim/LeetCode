class Solution {
public:
    int offset[100002];
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int l = 0;
        int r = queries.size();
        int ans = 100001;
        while(l <= r){
            int mid = (l + r) / 2;
            for(int i = 0 ; i < nums.size(); i++){
                offset[i] = 0;
            }
            for(int i = 0; i < mid; i++){
                offset[queries[i][0]] += queries[i][2];
                offset[queries[i][1] + 1] -= queries[i][2];
            }
            for(int i = 1; i < nums.size(); i++){
                offset[i] += offset[i-1];
            }
            bool success = true;
            for(int i = 0 ; i < nums.size() ;i++){
                if((nums[i] - offset[i]) > 0){
                    success = false;
                    break;
                }
            }
            if(success){
                ans = mid;
                r = mid - 1;
            } else{
                l = mid + 1;
            }
        }
        if( ans == 100001) return -1;
        return ans;
    }
};