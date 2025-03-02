class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        map<int, int > m;
        for(int i = 0 ; i < nums1.size(); i++){
            int id = nums1[i][0];
            int v = nums1[i][1];
            m[id] += v;
        }
        for(int i = 0 ; i < nums2.size(); i++){
            int id = nums2[i][0];
            int v = nums2[i][1];
            m[id] += v;
        }
        vector<vector<int>> ans;
        for (auto iter : m){
            int id = iter.first;
            int v = iter.second;
            ans.push_back({id, v});
        }
        return ans;
    }
};