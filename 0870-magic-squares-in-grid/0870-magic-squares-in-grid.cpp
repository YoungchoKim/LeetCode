class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int ans = 0;
        if (grid.size() < 3 || grid[0].size() < 3) return 0;
        for(int i = 0 ; i < grid.size() - 2; i++){
            for(int j = 0 ; j < grid[i].size() - 2; j++){
                int cnt = 0;
                int sum = 0;
                bool visited[10] = {false};
                for(int r =i; r < i + 3; r++){
                    for(int c = j; c < j + 3; c++){
                        if(grid[r][c] < 1 || grid[r][c] >= 10 || visited[grid[r][c]]) break;
                        cnt++;
                        visited[grid[r][c]] = true;
                    }
                }
                int sumArr[8] = {0};
                if (cnt == 9){
                    for(int k = 0 ; k < 3; k++){
                        sumArr[0] += grid[i][j+k];
                        sumArr[1] += grid[i+1][j+k];
                        sumArr[2] += grid[i+2][j+k];
                        sumArr[3] += grid[i+k][j];
                        sumArr[4] += grid[i+k][j+1];
                        sumArr[5] += grid[i+k][j+2];
                        sumArr[6] += grid[i+k][j+k];
                        sumArr[7] += grid[i+k][j+2-k];
                    }
                    bool isMagicGrid = true;
                    for(int k = 1 ; k < 8; k++){
                        if (sumArr[k] != sumArr[0]){
                            isMagicGrid = false;
                            break;
                        }
                    }
                    if (isMagicGrid){
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};