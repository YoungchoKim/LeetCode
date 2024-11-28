struct _node{
    int r;
    int c;
    int moveCnt;
    int removeCnt;
};
struct _heap{
    int size;
    _node arr[1000001];
    _heap(){
        size = 1;
    }
    bool _cmp(_node a, _node b){
        if(a.removeCnt != b.removeCnt){
            return a.removeCnt < b.removeCnt;
        }
        return a.moveCnt < b.moveCnt;

    }
    void push(_node a){
        arr[size++] = a;
        int idx = size -1;
        while(idx > 1 && _cmp(arr[idx], arr[idx/2])){
            _node tmp = arr[idx];
            arr[idx] = arr[idx/2];
            arr[idx/2] = tmp;
            idx /= 2;
        }
    }
    _node pop(){
        _node ret = arr[1];
        arr[1] = arr[--size];
        int i = 1;
        while(true){
            int j = i * 2;
            if (j >= size){
                break;
            }
            if((j + 1) < size && _cmp(arr[j+1], arr[j])){
                j++;
            }
            if(_cmp(arr[j], arr[i])){
                _node t = arr[i];
                arr[i] = arr[j];
                arr[j] = t;
                i = j;
            } else {
                break;
            }
        }

        return ret;

    }
    bool empty(){
        return size == 1;
    }
};
int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};

class Solution {
public:
    _heap que;
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int **visited = new int*[m];
        for(int i = 0 ; i < m; i++){
            visited[i] = new int[n];
            for(int j = 0 ; j < n ;j++){
                visited[i][j] = 1234567890;
            }
        }
        visited[0][0]= 0;
        que.push({0, 0, 0, 0});
        while(!que.empty()){
            _node nod = que.pop();
            if(nod.r == m - 1 && nod.c == n - 1){
                return nod.removeCnt;
            }
            for(int i = 0 ; i< 4; i++){
                int nr = nod.r + dy[i];
                int nc = nod.c + dx[i];
                if(nr < 0 || nr >= m || nc < 0 || nc >= n || visited[nr][nc] <= nod.moveCnt+1){
                    continue;
                }
                visited[nr][nc] = nod.moveCnt+1;
                if(grid[nr][nc] == 0){
                    que.push({nr, nc, nod.moveCnt+1, nod.removeCnt});
                } else {
                    que.push({nr, nc, nod.moveCnt+1, nod.removeCnt + 1});
                }
            }
        }

        return -1;
    }
};