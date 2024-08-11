class Solution {
public:
    int map[128][128];
    bool visited[128][128];
    int R, C;
    int ans = 0;
    void fill(int r, int c){
        if (r < 0 || r >= R || c < 0 || c >= C || map[r][c] == 1 || visited[r][c]){
            return;
        }
        visited[r][c] = true;
        fill(r + 1, c);
        fill(r, c + 1);
        fill(r - 1, c);
        fill(r, c - 1);
    }
    int regionsBySlashes(vector<string>& grid) {
        R = grid.size();
        C = grid[0].length();
        for(int r = 0 ; r < R; r++){
            for(int c = 0; c < C; c++){
                if (grid[r][c] == '/'){
                    map[3*r][3*c+2] = 1;
                    map[3*r+1][3*c+1] = 1;
                    map[3*r+2][3*c] = 1;
                } else if (grid[r][c] == '\\'){
                    map[3*r][3*c] = 1;
                    map[3*r+1][3*c+1] = 1;
                    map[3*r+2][3*c+2] = 1;

                }
            }
        }
        R *= 3;
        C *= 3;
        for(int r = 0 ; r < R; r++){
            for(int c = 0 ; c < C; c++){
                if (map[r][c] == 0 && !visited[r][c]) {
                    fill(r, c);
                    ans++;
                }
            }
        }
        return ans;
    }
};