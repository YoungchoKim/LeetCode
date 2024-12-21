class Solution {
public:
    vector<int> undirectAdj[30000];
    vector<int> directAdj[30000];
    vector<int> leafs[2];
    bool visited[30000];
    bool visited2[30000];
    int in[30000];
    int succeed = 0;
    void traversal(int root){
        visited[root] = true;
        int nextCnt = 0;
        for(int i = 0 ; i < undirectAdj[root].size(); i++){
            int next = undirectAdj[root][i];
            if(visited[next]){
                continue;
            }
            nextCnt++;
            directAdj[next].push_back(root);
            in[root]++;
            traversal(next);
        }
        if(nextCnt == 0){
            leafs[0].push_back(root);
        }
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        
        for(int i = 0 ; i < edges.size(); i++){
            int a = edges[i][0];
            int b = edges[i][1];
            undirectAdj[a].push_back(b);
            undirectAdj[b].push_back(a);
        }
        int root = 0;
        traversal(root);
        int leafIdx = 0;
        int ans = 0;
        bool end = false;
        while(true){
            leafs[leafIdx^1].clear();
            for(int i = 0 ; i < leafs[leafIdx].size(); i++){
                int cur = leafs[leafIdx][i];
                if(succeed >= n-1 && cur == root){
                    end = true;
                    break;
                }
                if(cur == root){
                    continue;
                }
                int next = directAdj[cur][0];
                if(visited2[cur]) continue;
                visited2[cur] = true;
                succeed++;
                if(values[cur] % k){ 
                    values[next] = (values[next] + values[cur]) % k;
                } else{
                    ans++;
                }
                in[next]--;
                if(in[next] == 0){
                    leafs[leafIdx^1].push_back(next);
                }
            }
            if(end) break;
            leafIdx ^= 1;
        }
        
        if(values[root] % k){
            return 1;
        } else{
            return ans + 1;
        }
    }
};