class Solution {
    vector<int> adj[100001];
    bool visited[100001] = {false,};
    bool visited2[100001] = {false,};
    bool isLeaf[100001] = {false,};
    int ans = -1000000001;
public:

    int goBobAndUpdateAmount(int node, int depth, int bob, vector<int>& amount){
        if(visited[node]) return 100001;
        if(node == bob){
            amount[node] = 0;
            return depth;
        }
        visited[node] = true;
        int distanceBob = 100001;
        for(int i = 0 ; i < adj[node].size(); i++){
            int next = adj[node][i];
            distanceBob = goBobAndUpdateAmount(next, depth + 1, bob, amount);
            if(distanceBob == 100001) continue;
            if(depth > (distanceBob/2)){
                amount[node] = 0;
            } 
            if(depth == (distanceBob/2) && distanceBob %2 == 0){
                amount[node]/=2;
            }
            break;
        }
        return distanceBob;
    }
    void dfs(int node, int sum, vector<int>& amount){
        if(visited2[node]) return;
        visited2[node] = true;
        sum += amount[node];
        if(isLeaf[node] && ans < sum){
            ans = sum;
        }
        for(int i = 0 ; i < adj[node].size(); i++){
            int next = adj[node][i];
            dfs(next, sum, amount);
        }
    }
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        for(int i = 0 ; i < edges.size(); i++){
            int a = edges[i][0];
            int b = edges[i][1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        for(int i = 1; i <= edges.size(); i++){
            if(adj[i].size() == 1) isLeaf[i] = true;
        }
        goBobAndUpdateAmount(0, 0, bob, amount);
        
        dfs(0, 0, amount);
        return ans;
    }
};