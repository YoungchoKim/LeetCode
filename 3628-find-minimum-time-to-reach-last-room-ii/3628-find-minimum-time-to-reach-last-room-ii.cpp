struct _pair{
    int r;
    int c;
    int time;
    int dis;
};
struct _heap{
    int size;
    _pair arr[750*750+1];
    _heap(){
        size = 1;
    }
    void push(_pair a){
        arr[size++] = a;
        int idx = size - 1;
        while(idx > 1 && arr[idx/2].time > arr[idx].time){
            _pair t = arr[idx/2];
            arr[idx/2] = arr[idx];
            arr[idx] = t;
            idx /= 2;
        }
    }
    _pair pop(){
        _pair ret = arr[1];
        arr[1] = arr[--size];
        int i = 1;
        while(true){
            int j = i * 2;
            if(j >= size){
                break;
            }
            if((j+1) < size && arr[j].time > arr[j+1].time){
                j++;
            }
            if(arr[i].time > arr[j].time){
                _pair t = arr[i];
                arr[i] = arr[j];
                arr[j] = t;
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
public:
    _heap h;
    bool visited[751][751];
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int R = moveTime.size();
        int C = moveTime[0].size();
        int dy[] = {0, 1, 0, -1};
        int dx[] = {1, 0, -1, 0};
        visited[0][0] = true;
        h.push({0,0,0,0});
        while(!h.empty()){
            _pair p = h.pop();
            if(p.r == (R-1) && p.c == (C-1) ){
                return p.time;
            }
            for(int i = 0 ; i < 4; i++){
                int nr = p.r + dy[i];
                int nc = p.c + dx[i];
                if(nr < 0 || nr >= R || nc < 0 || nc >= C || visited[nr][nc]){
                    continue;
                }
                int nextTime = max(p.time, moveTime[nr][nc]) + 1 + (p.dis %2);
                h.push({nr, nc, nextTime, p.dis+1});
                visited[nr][nc] = true;
            }
        }
        return -1;
    }
};