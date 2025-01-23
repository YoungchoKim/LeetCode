struct _node{
    int r;
    int c;
};
class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int ans = 0;
        int M = grid.size();
        int N = grid[0].size();
        for(int i = 0 ; i < M; i++){
            for(int j = 0 ; j < N ;j++){
                queue<_node> que;
                if(grid[i][j]){
                    que.push({i, j});
                    grid[i][j] = 0;
                    int cnt = 1;
                    while(!que.empty()){
                        _node nod = que.front();
                        que.pop();
                        for(int k = 0 ; k < N; k++){
                            if(grid[nod.r][k]){
                                que.push({nod.r, k});
                                grid[nod.r][k] = 0;
                                cnt++;
                            }
                        }
                        for(int k = 0 ; k < M; k++){
                            if(grid[k][nod.c]){
                                que.push({k, nod.c});
                                grid[k][nod.c] = 0;
                                cnt++;
                            }
                        }
                    }
                    if(cnt >= 2) ans += cnt;
                }
            }
        }
        return ans;
    }
};