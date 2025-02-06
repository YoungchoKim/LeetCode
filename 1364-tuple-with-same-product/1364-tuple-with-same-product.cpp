class Solution {
public:
    bool num[10001];
    int tupleSameProduct(vector<int>& nums) {
        vector<int> nums2;
        for(int i = 0 ; i < nums.size(); i++){
            if(num[nums[i]]){
                continue;
            }
            nums2.push_back(nums[i]);
            num[nums[i]] = true;
        }
        sort(nums2.begin(), nums2.end());
        vector<int> nums3;
        for(int i = 0 ; i < nums2.size(); i++){
            for(int j = i+1 ; j < nums2.size(); j++){
                nums3.push_back(nums2[i] * nums2[j]);
            }
        }
        int ans = 0;
        sort(nums3.begin(), nums3.end());
        int cnt = 1;
        int cur = nums3[0];
        for(int i = 1 ; i < nums3.size();i++){
            cout << nums3[i] << endl;
            if(cur != nums3[i]){
                if(cnt >= 2){
                    ans += (cnt * (cnt - 1))/2 * 8;
                }
                cnt = 0;
            }
            cnt++;
            cur = nums3[i];
        }
        if(cnt >= 2){
            ans += (cnt * (cnt - 1))/2 * 8;
        }
        return ans;
    }
};