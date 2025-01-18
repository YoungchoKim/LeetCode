struct _node{
    int r;
    int c;
    int cost;
};

bool minHeap(_node& a, _node& b){
    return a.cost > b. cost;
}

struct _heap{
    _node arr[40001];
    int size;
    bool (*cmp)(_node& a, _node& b);
    _heap(){
        size = 1;
    }
    void push(_node a){
        arr[size++] = a;
        int idx = size - 1;
        while(idx > 1 && cmp(arr[idx/2], arr[idx])){
            _node tmp = arr[idx/2];
            arr[idx/2] = arr[idx];
            arr[idx] = tmp;
            idx /= 2;
        }
    }
    _node pop(){
        _node ret = arr[1];
        arr[1] = arr[--size];
        int i = 1;
        while(true){
            int j = i * 2;
            if(j >= size) break;
            if(j+1 < size && cmp(arr[j], arr[j+1])){
                j++;
            }
            if(cmp(arr[i], arr[j])){
                _node tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
                i = j;
            } else{
                break;
            }
        }
        return ret;
    }
    bool empty(){
        return size == 1;
    }
};

class Solution {
    _heap que;
    int cost[100][100];
public:
    int minCost(vector<vector<int>>& grid) {
        int M = grid.size();
        int N = grid[0].size();
        for(int i = 0 ; i < M; i++){
            for(int j = 0 ; j < N; j++){
                cost[i][j] = 200;
            }
        }
        que.cmp = minHeap;
        que.push({0, 0, 0});
        cost[0][0] = 0;
        int dy[] = {0, 0, 0, 1, -1};
        int dx[] = {0, 1, -1, 0, 0};
        while(!que.empty()){
            _node nod = que.pop();
            if(nod.r == (M - 1) && nod.c == (N - 1)){
                return nod.cost;
            }
            for(int i = 1; i <= 4; i++){
                int nr = nod.r + dy[i];
                int nc = nod.c + dx[i];
                if(nr < 0 || nr >= M || nc < 0 || nc >= N){
                    continue;
                }
                int c = nod.cost;
                if(i != grid[nod.r][nod.c]){
                    c++;
                }
                if(cost[nr][nc] <= c) continue;
                cost[nr][nc] = c;
                que.push({nr, nc, c});
            }
        }
        return -1;
    }
};