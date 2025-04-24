class Solution {
public:
    unordered_map<int, bool> m;
    int countCompleteSubarrays(vector<int>& nums) {
        
        for(int i = 0 ; i < nums.size(); i++){
            m[nums[i]] = true;
        }
        int ans = 0;
        for(int i = 0 ; i < nums.size(); i++){
            unordered_map<int, bool> m2;
            for(int j = i; j >= 0; j--){
                m2[nums[j]] = true;
                if(m2.size() == m.size()){
                    ans += j + 1;
                    break;
                }
            }
        }
        return ans;
    }
};