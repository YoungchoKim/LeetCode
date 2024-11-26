class Solution {
public:
    vector<int> adj[101];
    set<int> leaf;
    bool visited[101];
    set<int> start;
    void dfs(int cur){
        if(visited[cur]) return;
        visited[cur] = true;
        if(adj[cur].size() == 0){
            leaf.insert(cur);
            return;
        }
        for(int i = 0 ; i < adj[cur].size(); i++){
            int next = adj[cur][i];
            dfs(next);
        }
    }
    int findChampion(int n, vector<vector<int>>& edges) {
        if (n == 1) return 0;
        for(int  i = 0 ; i < edges.size(); i++){
            int a = edges[i][0];
            int b = edges[i][1];
            adj[b].push_back(a);
            start.insert(a);
            start.insert(b);
        }
        if(n != start.size()){
            return -1;
        }
        for(auto iter = start.begin(); iter != start.end(); iter++){
            dfs(*iter);
        }
        if(leaf.size() == 1) return *(leaf.begin());
        return -1;
    }
};