struct NODE {
    int num;
    int time;

    bool operator <(NODE &b){
        return time < b.time;
    }
};

template <typename T>
struct _heap{
    int size;
    T arr[80001];
    _heap(){
        size = 1;
    }
    bool cmp(T a, T b){
        return a < b;
    }
    bool empty(){
        return size == 1;
    }
    void push(T a){
        arr[size++] = a;
        int idx = size - 1;
        while(idx > 1 && cmp(arr[idx], arr[idx/2])){
            T tmp = arr[idx];
            tmp = arr[idx/2];
            arr[idx/2] = tmp;
            idx /= 2;
        }
    }
    T pop(){
        T ret = arr[1];
        arr[1] = arr[--size];
        int i = 1;
        while(true){
            int j = i * 2;
            if (j >= size) break;
            if (j+1 < size && cmp(arr[j+1], arr[j])){
                j++;
            }
            if (cmp(arr[j], arr[i])){
                T tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
                i = j;
            } else{
                break;
            }
        }

        return ret;
    }
};

class Solution {
public:
    _heap<NODE> h;
    queue<NODE> q;
    vector<int> visited[10001];
    vector<int> adj[10001];
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        for(int i = 0 ; i < edges.size(); i++){
            int a = edges[i][0];
            int b = edges[i][1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        visited[1].push_back(0);
        for(int i = 0 ; i < adj[1].size(); i++){
            int v = adj[1][i];
            h.push({v, time});
            visited[v].push_back(time);
        }
        int minCost = 1234567890;
        int minSecondCost = 1234567890;

        while(!h.empty()){
            NODE a = h.pop();
            if (a.num == n && a.time < minCost){
                minSecondCost = minCost;
                minCost = a.time;
            }
            if (a.num == n && a.time > minCost && minSecondCost > a.time){
                minSecondCost = a.time;
            }
            for(int i = 0 ; i < adj[a.num].size(); i++){
                int next = adj[a.num][i];
                if (visited[next].size() >= 2){
                    continue;
                }
                int cost = 0;
                if ((a.time / change)%2){
                    cost = (change - (a.time%change)) + a.time + time;
                } else {
                    cost = a.time + time;
                }

                if(visited[next].size() == 0){
                    visited[next].push_back(cost);
                } else{
                    if (visited[next][0] == cost){
                        continue;
                    }
                    visited[next].push_back(cost);
                }
                h.push({next, cost});
            }
        }
        return minSecondCost;
    }
};