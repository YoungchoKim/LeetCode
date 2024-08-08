class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> ans;
        int dy[] = {0, 1, 0, -1};
        int dx[] = {1, 0, -1, 0};
        int ans_cnt = 0;
        int cnt = 1;
        int dir = 0;
        ans.push_back({rStart, cStart});
        ans_cnt++;
        while(ans_cnt < rows * cols){
            for(int i = 0 ; i < 2; i++){
                for(int j = 0 ; j < cnt; j++){
                    rStart += dy[dir];
                    cStart += dx[dir];
                    if (rStart < 0 || rStart >= rows || cStart < 0 || cStart >= cols){
                        continue;
                    }
                    ans.push_back({rStart, cStart});
                    ans_cnt++;
                }
                dir = (dir + 1) % 4;
            }
            cnt++;
        }
        return ans;
    }
};