struct _node{
    int n;
    int cnt;
};
class Solution {
public:
    vector<int> adj[500];
    

    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> ans;
        for(int i = 0 ; i < n-1; i++){
            adj[i].push_back(i+1);
        }
        for(int i = 0 ; i < queries.size(); i++){
            queue<_node> que;
            bool visited[500] = {false};
            int a = queries[i][0];
            int b = queries[i][1];
            adj[a].push_back(b);
            
            visited[0] = true;
            for(int j = 0 ; j < adj[0].size(); j++){
                que.push({adj[0][j], 1});
                visited[adj[0][j]] = true;
            }

            while(!que.empty()){
                _node nod = que.front();
                que.pop();
                if(nod.n == n-1){
                    ans.push_back(nod.cnt);
                    break;
                }
                for(int j = 0 ; j < adj[nod.n].size(); j++){
                    int next = adj[nod.n][j];
                    if(visited[next]) continue;
                    visited[next] = true;
                    que.push({next, nod.cnt + 1});
                }
            }
        }
        return ans;
    }
};