class Solution {
public:
    int visited1[501][501];
    int visited2[501][501];
    bool GRID1[501][501];
    bool GRID2[501][501];
    int R, C;
    void fill(int r, int c, int v){
        if (r < 0 || r >= R || c < 0 || c >= C || visited1[r][c] || GRID1[r][c] == 0) return;
        visited1[r][c] = v;
        fill(r + 1, c, v);
        fill(r - 1, c, v);
        fill(r, c + 1, v);
        fill(r, c - 1, v);
    }
    bool checkSubIsland(int r, int c, int v){
        if (r < 0 || r >= R || c < 0 || c >= C || visited2[r][c] || GRID2[r][c] == 0) return true;
        if (visited1[r][c] != v) return false;
        visited2[r][c] = true;
        bool ret = true;
        if (!checkSubIsland(r + 1, c, v)){
            ret = false;
        }
        if (!checkSubIsland(r - 1, c, v)){
            ret = false;
        }
        if (!checkSubIsland(r, c + 1, v)){
            ret = false;
        }
        if (!checkSubIsland(r, c - 1, v)){
            ret = false;
        }

        return ret;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        R = grid1.size();
        C = grid1[0].size();
        for(int i = 0 ; i < R; i++){
            for(int j = 0 ; j < C; j++){
                GRID1[i][j] = grid1[i][j];
                GRID2[i][j] = grid2[i][j];
            }
        }
        int cnt = 1;
        for(int i = 0 ; i < R; i++){
            for(int j = 0 ; j < C; j++){
                if(GRID1[i][j] && !visited1[i][j]){
                    fill(i, j, cnt);
                    cnt++;
                }
            }
        }


        int ans = 0;
        for(int i = 0; i < R; i++){
            for(int j = 0 ; j < C; j++){
                if(GRID2[i][j] && visited1[i][j] && !visited2[i][j]){
                    if(checkSubIsland(i, j, visited1[i][j])){
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};