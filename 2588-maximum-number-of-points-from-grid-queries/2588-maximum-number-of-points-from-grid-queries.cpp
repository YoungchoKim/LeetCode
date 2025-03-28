struct _node{
    int r;
    int c;
    int v;
};

template <typename T>
struct _heap{
    T arr[1000001];
    int size;
    _heap(){
        size = 1;
    }
    void push(T a){
        arr[size++] = a;
        int idx = size - 1;
        while(idx > 1 && arr[idx/2].v > arr[idx].v){
            T t = arr[idx/2];
            arr[idx/2] = arr[idx];
            arr[idx] = t;
            idx /= 2;
        }
    }
    T pop(){
        T ret = arr[1];
        arr[1] = arr[--size];
        int i = 1;
        while(true){
            int j = i * 2;
            if(j >= size) break;
            if(j + 1 < size && arr[j].v > arr[j+1].v){
                j++;
            }
            if(arr[i].v > arr[j].v){
                T t = arr[i];
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
    _heap<_node> h;
    bool visited[1001][1001];
    int answer[1000001] = {0};
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        vector<int> ans;
        int cur_query = 0;
        int dy[] = {0, 1, 0, -1};
        int dx[] = {1, 0, -1, 0};

        visited[0][0] = true;
        h.push({0, 0, grid[0][0]});
        
        while(!h.empty()){
            _node nod = h.pop();
            cur_query = max(cur_query, nod.v);
            answer[cur_query]++;
            for(int i = 0 ; i < 4; i++){
                int nr = nod.r + dy[i];
                int nc = nod.c + dx[i];
                if(nr < 0 || nr >= grid.size() || nc < 0 || nc >= grid[0].size() || visited[nr][nc]){
                    continue;
                }
                visited[nr][nc] = true;
                h.push({nr, nc, grid[nr][nc]});
            }
        }
        for(int i = 1 ; i < 1000001; i++){
            answer[i] = answer[i-1] + answer[i];
        }
        for(int i = 0 ; i < queries.size(); i++){
            ans.push_back(answer[queries[i]-1]);
        }
        return ans;
    }
};