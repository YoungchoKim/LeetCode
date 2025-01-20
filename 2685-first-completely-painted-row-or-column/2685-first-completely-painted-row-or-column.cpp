class Solution {
public:
    int vtoi[100001];
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        for(int i = 0 ; i < arr.size(); i++){
            vtoi[arr[i]] = i;
        }
        int m = mat.size();
        int n = mat[0].size();
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                mat[i][j] = vtoi[mat[i][j]];
            }
        }
        int ans = 100000;
        for(int i = 0 ; i < m; i++){
            int maxIdx = -1;
            for(int j = 0 ; j < n ; j++){
                maxIdx = max(maxIdx, mat[i][j]);
            }
            ans = min(ans, maxIdx);
        }
        for(int i = 0; i < n; i++){
            int maxIdx = -1;
            for(int j = 0; j < m; j++){
                maxIdx = max(maxIdx, mat[j][i]);
            }
            ans = min(ans, maxIdx);
        }
        return ans;
    }
};