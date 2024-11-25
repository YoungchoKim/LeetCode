struct _node{
    char board[2][3];
    int cnt;
};
int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};
class Solution {
public:
    bool visited[6][6][6][6][6][6];
    queue<_node> que;
    int slidingPuzzle(vector<vector<int>>& board) {
        _node init;
        for(int i = 0 ; i < 2; i++){
            for(int j = 0; j < 3; j++){
                init.board[i][j] = board[i][j];
            }
        }
        init.cnt = 0;
        que.push(init);
        visited[board[0][0]][board[0][1]][board[0][2]][board[1][0]][board[1][1]][board[1][2]] = true;
        while(!que.empty()){
            _node nod = que.front();
            que.pop();
            if(nod.board[1][2] == 0 && nod.board[0][0] == 1 && 
            nod.board[0][1] == 2 && nod.board[0][2] == 3 &&
            nod.board[1][0] == 4 && nod.board[1][1] == 5){
                return nod.cnt;
            }
            int r=-1, c = -1;
            for(int i = 0; i < 2; i++){
                for(int j = 0; j < 3; j++){
                    if(nod.board[i][j] == 0){
                        r = i;
                        c = j;
                        break;
                    }
                }
                if(r != -1) break;
            }

            for(int i = 0 ; i < 4; i++){
                int nr = r + dy[i];
                int nc = c + dx[i];
                if(nr < 0 || nr >= 2 || nc < 0 || nc >= 3){
                    continue;
                }
                _node next = nod;
                next.cnt++;
                char t = next.board[nr][nc];
                next.board[nr][nc] = next.board[r][c];
                next.board[r][c] = t;
                if(visited[next.board[0][0]][next.board[0][1]][next.board[0][2]][next.board[1][0]][next.board[1][1]][next.board[1][2]] ){
                    continue;
                }

                visited[next.board[0][0]][next.board[0][1]][next.board[0][2]][next.board[1][0]][next.board[1][1]][next.board[1][2]] = true;
                que.push(next);
            }

        }
        return -1;
    }
};