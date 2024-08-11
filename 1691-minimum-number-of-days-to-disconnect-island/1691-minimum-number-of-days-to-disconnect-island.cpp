class Solution {
public:
    int R;
    int C;
    vector<vector<int>> map;
    void fill(int r, int c, bool visited[][31]){
        if (r < 0 || r >= R || c < 0 || c >= C || map[r][c] == 0 || map[r][c] == 3 || visited[r][c]){
            return;
        }
        visited[r][c]  = true;
        fill(r + 1, c, visited);
        fill(r, c + 1, visited);
        fill(r - 1, c, visited);
        fill(r, c - 1, visited);
    }
    int getIsland(){
        bool visited[31][31];
        int cnt = 0;
        for(int i = 0 ; i < R; i++){
            for(int j = 0 ; j < C; j++){
                visited[i][j] = false;
            }
        }
        for(int i = 0 ; i < R; i++){
            for(int j = 0 ; j < C; j++){
                if(map[i][j] == 1 && !visited[i][j]){
                    cnt++;
                    fill(i, j, visited);
                }
            }
        }
        return cnt;
    }
    bool closeWater(int r, int c){
        int dy[] = {1, 0, -1, 0};
        int dx[] = {0, 1, 0, -1};
        for(int i = 0 ;i  < 4; i++){
            int nr = r + dy[i];
            int nc = c + dx[i];
            if(nr < 0 || nr >= R || nc < 0 || nc >= C){
                return true;
            }
            if (map[nr][nc] == 0){
                return true;
            }
        }
        return false;
    }
    int minDays(vector<vector<int>>& grid) {
        R = grid.size();
        C = grid[0].size();
        map = grid;
        int ans = 0;
        int island_cnt = getIsland();
        while(island_cnt == 1){
            for(int i = 0 ; i < R; i++){
                for(int j = 0 ; j < C; j++){
                    if(map[i][j] == 0) continue;
                    map[i][j] = 0;
                    int tmpCnt = getIsland();
                    if(tmpCnt != 1) return ans + 1;
                    map[i][j] = 1;
                }
            }
            for(int i = 0 ; i < R ; i++){
                for(int j = 0 ; j < C; j++){
                    if(map[i][j] == 1 && closeWater(i, j)){
                        map[i][j] = 3;
                    }
                }
            }
            for(int i = 0 ; i < R ; i++){
                for(int j = 0 ; j < C; j++){
                    if(map[i][j] == 3){
                        map[i][j] = 1;
                        int tmpCnt = getIsland();
                        if(tmpCnt != 1) return ans + 2;
                        map[i][j] = 3;
                    }
                }
            }

            for(int i = 0 ; i < R ; i++){
                for(int j = 0 ; j < C; j++){
                    if(map[i][j] == 3){
                        map[i][j] = 0;
                    }
                }
            }
            


            ans += 2;
            island_cnt = getIsland();
        }
        
        return ans;
    }
};