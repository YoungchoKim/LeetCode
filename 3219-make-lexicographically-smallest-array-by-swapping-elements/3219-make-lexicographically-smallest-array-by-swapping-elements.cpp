class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<vector<int>> groups;
        unordered_map<int, int> valToGrp;
        int numIdx = 0;
        vector<int> nums2;
        for(int i = 0 ; i < nums.size(); i++){
            nums2.push_back(nums[i]);
        }
        sort(nums2.begin(), nums2.end());
        while(numIdx < nums2.size()){
            groups.push_back(vector<int> ());
            long long minv = nums2[numIdx];
            long long maxv = nums2[numIdx];
            while(minv - limit <= nums2[numIdx] && nums2[numIdx] <= maxv + limit){
                groups.back().push_back(nums2[numIdx]);
                valToGrp[nums2[numIdx]] = groups.size() - 1;
                numIdx++;
                if(numIdx >= nums2.size()) break;
                if(minv > nums2[numIdx] && nums2[numIdx] >= minv - limit){
                    minv = nums2[numIdx];
                }
                if(maxv < nums2[numIdx] && nums2[numIdx] <= maxv + limit){
                    maxv = nums2[numIdx];
                }
            }
        }
        unordered_map<int, int> groupIdx;
        for(int i = 0 ; i < nums.size(); i++){
            int idx = valToGrp[nums[i]];
            nums[i] = groups[idx][groupIdx[idx]];
            groupIdx[idx]++;
        }
        return nums;
    }
};