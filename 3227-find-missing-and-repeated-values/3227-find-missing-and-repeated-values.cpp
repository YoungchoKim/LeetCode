class Solution {
public:
    bool appear[2501] = {false,};
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int N = grid.size();
        vector<int> ans;
        for(int i = 0 ; i < N; i++){
            for(int j = 0 ; j < N; j++){
                if(appear[grid[i][j]]){
                    ans.push_back(grid[i][j]);
                }
                appear[grid[i][j]] = true;
            }
        }
        for(int i = 1 ; i <= N*N; i++){
            if(!appear[i]){
                ans.push_back(i);
                return ans;
            }

        }
        return ans;
    }
};