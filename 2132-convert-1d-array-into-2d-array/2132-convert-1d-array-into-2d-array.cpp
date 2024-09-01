class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> ans;
        if (m*n != original.size()) return {};
        for(int i = 0 ; i < m; i++){
            ans.push_back(vector<int> ());
            for(int j = 0 ; j < n; j++){
                ans[i].push_back(original[n*i + j]);
            }
        }
        return ans;
    }
};