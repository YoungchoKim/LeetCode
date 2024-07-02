class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> answer;
        unordered_map<int, int> cnt;
        for(int i = 0 ; i < nums1.size(); i++){
            cnt[nums1[i]]++;
        }
        for(int i = 0 ; i < nums2.size(); i++){
            if(cnt[nums2[i]]){
                cnt[nums2[i]]--;
                answer.push_back(nums2[i]);
            }
        }
        return answer;
    }
};