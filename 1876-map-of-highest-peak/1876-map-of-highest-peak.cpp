struct _node{
    int r;
    int c;
};
class Solution {
public:
    queue<_node> que;
    vector<vector<int>> ans;
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int M = isWater.size();
        int N = isWater[0].size();
        for(int i = 0 ; i < M; i++){
            ans.push_back(vector<int>());
            for(int j = 0 ; j < N; j++){
                ans[i].push_back(-1);
                if(isWater[i][j]){
                    que.push({i, j});
                    ans[i][j] = 0;
                }
            }
        }
        int dy[] = {1, 0, -1, 0};
        int dx[] = {0, 1, 0, -1};
        while(!que.empty()){
            _node nod = que.front();
            que.pop();
            for(int i = 0; i < 4; i++){
                int nr = nod.r + dy[i];
                int nc = nod.c + dx[i];
                if(nr < 0 || nr >= M || nc < 0 || nc >= N || ans[nr][nc] != -1){
                    continue;
                }
                ans[nr][nc] = ans[nod.r][nod.c] + 1;
                que.push({nr, nc});
            }
        }
        return ans;
    }
};