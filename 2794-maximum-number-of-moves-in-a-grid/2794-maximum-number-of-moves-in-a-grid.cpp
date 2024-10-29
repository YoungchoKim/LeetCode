struct _pair{
    int r;
    int c;
};
struct _queue{
    _pair arr[1000001];
    int front = 0;
    int rear = 0;
    void pop(){
        front++;
    }
    void push(_pair a){
        arr[rear++] = a;
    }
    _pair peek(){
        return arr[front];
    }
    bool empty(){
        return front == rear;
    }
    
};
class Solution {
public:
    int visited[1000][1000];
    _queue que;
    
    int maxMoves(vector<vector<int>>& grid) {
        int dy[] = {1, -1, 0};
        int dx[] = {1, 1, 1};
        int R = grid.size();
        int C = grid[0].size();
        int ans = 0;
        for(int i = 0 ; i < grid.size(); i++){
            que.push({i, 0});
            visited[i][0] = 0;
        }
        while(!que.empty()){
            _pair num = que.peek();
            que.pop();
            ans = max(ans, visited[num.r][num.c]);
            for(int i = 0 ; i < 3; i++){
                int ny = num.r + dy[i];
                int nx = num.c + dx[i];
                if(ny < 0 || ny >= R || nx < 0 || nx >= C || 
                    visited[num.r][num.c] + 1 <= visited[ny][nx] ||
                    grid[num.r][num.c] >= grid[ny][nx]){
                    continue;
                }
                visited[ny][nx] = visited[num.r][num.c] + 1;
                que.push({ny, nx});
            }
        }
        return ans;
    }
};