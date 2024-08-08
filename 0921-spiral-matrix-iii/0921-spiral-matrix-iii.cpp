class Solution {
public:

    int map[300][300];
    int offset = 101;
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> ans;
        int dy[] = {0, 1, 0, -1};
        int dx[] = {1, 0, -1, 0};
        int ans_cnt = 0;
        for(int i = 0 ; i < rows; i++){
            for(int j = 0; j < cols; j++){
                map[offset + i][offset + j] = 1;
            }
        }

        int cnt = 1;
        int dir = 0;
        ans.push_back({rStart, cStart});
        ans_cnt++;
        while(ans_cnt < rows * cols){
            for(int i = 0 ; i < 2; i++){
                for(int j = 0 ; j < cnt; j++){
                    rStart += dy[dir];
                    cStart += dx[dir];
                    if (map[rStart + offset][cStart+offset]){
                        ans.push_back({rStart, cStart});
                        ans_cnt++;
                    }
                }
                dir = (dir + 1) % 4;
            }
            cnt++;
        }
        return ans;
    }
};