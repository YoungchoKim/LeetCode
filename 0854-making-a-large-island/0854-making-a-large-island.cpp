class Solution {
public:
    int groups[62501];
    int groupSize;
    int R;
    int C;
    set<int> aroundGroup[500][500];
    void calcGroupCnt(vector<vector<int>>& grid, int r, int c, int& cnt, int visited[500][500],int groupIdx){
        if(r < 0 || r >= R || c <0 || c >= C || visited[r][c] || grid[r][c] == 0){
            return;
        }
        visited[r][c] = groupIdx;
        cnt++;
        calcGroupCnt(grid, r+1, c, cnt, visited, groupIdx);
        calcGroupCnt(grid, r-1, c, cnt, visited, groupIdx);
        calcGroupCnt(grid, r, c+1, cnt, visited, groupIdx);
        calcGroupCnt(grid, r, c-1, cnt, visited, groupIdx);
    }
    int largestIsland(vector<vector<int>>& grid) {
        R = grid.size();
        C = grid[0].size();
        int visited[500][500] = {0};
        for(int i = 0 ; i < R; i++){
            for(int j = 0 ; j < C; j++){
                if(grid[i][j] == 1 && visited[i][j] == 0){
                    int cnt = 0;
                    groupSize++;
                    calcGroupCnt(grid, i, j, cnt, visited, groupSize);
                    groups[groupSize] = cnt;
                }        
            }
        }
        int ans = 0;
        for(int i = 1 ; i <= groupSize; i++){
            ans = max(ans, groups[i]);
        }


        int dy[] = {1, 0, -1, 0};
        int dx[] = {0, 1, 0, -1};
        for(int i = 0 ; i < R; i++){
            for(int j = 0 ; j < C; j++){
                if(visited[i][j]) continue;
                for(int d = 0; d < 4; d++){
                    int nr = i + dy[d];
                    int nc = j + dx[d];
                    if(nr < 0 || nr >= R || nc < 0 || nc >= C || visited[nr][nc] == 0){
                        continue;
                    }
                    aroundGroup[i][j].insert(visited[nr][nc]);
                }
            }
        }
        for(int i = 0 ; i < R; i++){
            for(int j = 0 ; j < C; j++){
                int ans2 = 0;
                for(auto iter : aroundGroup[i][j]){
                    ans2 += groups[iter];
                }
                ans = max(ans, ans2 + 1);
            }
        }

        return ans;
    }
};