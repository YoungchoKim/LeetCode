
int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, 1, -1};
class Solution {
public:
    vector< vector<int>> map;
    void fill(int m, int n, int r, int c, int dir, int v){
        if(r < 0 || r >= m || c < 0 || c >= n || map[r][c] == 2 || map[r][c] == v){
            return;
        }
        map[r][c] = v; 
        fill(m, n, r + dy[dir], c + dx[dir], dir, v);
    }
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        for(int i = 0 ; i < m; i++){
            map.push_back(vector<int>());
            for(int j = 0; j < n; j++){
                map[i].push_back(0);
            }
        }
        for(int i = 0; i < walls.size(); i++){
            int r = walls[i][0];
            int c = walls[i][1];
            map[r][c] = 2;
        }
        for(int i = 0 ; i < guards.size(); i++){
            int r = guards[i][0];
            int c = guards[i][1];
            for(int j = 0 ; j < 4; j++){
                fill(m, n, r + dy[j], c + dx[j], j, j < 2 ? 4 : 5);
            }
            map[r][c] = 1;
        }
        int ans = 0;
        for(int i = 0 ; i < m; i++){
            for(int j = 0 ; j < n; j++){
                if(map[i][j] == 0){
                    ans++;
                }
            }
        }
        return ans;
    }
};