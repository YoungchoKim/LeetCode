class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m = grid.size();
        int n = grid[0].size();
        int minValue = 1000000;
        for(int i = 0 ; i < m; i++){
            for(int j = 0 ; j < n; j++){
                if(minValue > grid[i][j]){
                    minValue = grid[i][j];
                }
            }
        }
        int sum = 0;        
        for(int i = 0 ; i < m; i++){
            for(int j = 0 ; j < n; j++){
                grid[i][j] -= minValue;
                if(grid[i][j] % x != 0) return -1;
                grid[i][j] /= x;
                sum += grid[i][j];
            }
        }
        double temp = sum / double(m*n);
        int goal = temp + 0.5;
        int ans = 1000000001;
        for(int k = -20; k <= 20; k++){
            int goal2 = goal + k;
            int sum2 = 0;
            for(int i = 0 ; i < m; i++){
                for(int j = 0 ; j < n; j++){
                    sum2 += abs(goal2 - grid[i][j]);
                }
            }
            ans = min(ans, sum2);
        }
        
        return ans;
    }
};