class Solution {
public:
    bool traversalCycle(int cur, vector<vector<int>> graph, int color[]){
        color[cur] = 1;
        for(int i = 0 ; i < graph[cur].size(); i++){
            int next = graph[cur][i];
            if (color[next] == 0 && traversalCycle(next, graph, color)){
                return true;
            } else if (color[next] == 1){
                return true;
            }
        }
        color[cur] = 2;
        return false;
    }
    bool findCycle(int k, vector<vector<int>> &graph){
        int *color = new int[k];
        for(int i = 0 ; i < k; i++){
            color[i] = 0;
        }
        for(int i = 0 ; i < k ;i++){
            if (color[i] != 0) continue;
            if (traversalCycle(i, graph, color)){
                return true;
            }
        }
        return false;
    }

    void traversalAnswer(int cur, vector<vector<int>> &graph, vector<int> &ans, bool visited[]){
        if(visited[cur]) return;
        visited[cur] = true;
        for(int i = 0 ; i < graph[cur].size(); i++){
            int next = graph[cur][i];
            traversalAnswer(next, graph, ans, visited);
        }
        ans.push_back(cur);
    }
    void getAnswer(int k, vector<vector<int>> &graph, vector<int> &ans){
        bool *visited = new bool[k];
        for(int i = 0 ; i < k; i++){
            visited[i] = false;
        }
        for(int i = 0; i < k; i++){
            if (visited[i]) continue;
            traversalAnswer(i, graph, ans, visited);
        }
        reverse(ans.begin(), ans.end());
    }

    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<vector<int>> graph1(k);
        vector<vector<int>> graph2(k);
        for(int i = 0 ; i < rowConditions.size(); i++){
            int a = rowConditions[i][0];
            int b = rowConditions[i][1];
            graph1[a - 1].push_back(b - 1);
        }
        for(int i = 0 ; i < colConditions.size(); i++){
            int a = colConditions[i][0];
            int b = colConditions[i][1];
            graph2[a - 1].push_back(b - 1);
        }
        if (findCycle(k, graph1) || findCycle(k, graph2)){
            return {};
        }

        vector<int> ans1, ans2;
        getAnswer(k, graph1, ans1);
        getAnswer(k ,graph2, ans2);

        vector<vector<int>> ans;
        map<int, int> m;
        for(int i = 0 ; i < k; i++){
            m[ans2[i]] = i;
            ans.push_back(vector<int>());
            for(int j = 0 ; j < k; j++){
                ans[i].push_back(0);
            }
        }
        for(int i = 0 ; i < k; i++){
            ans[i][m[ans1[i]]] = ans1[i] + 1;
        }
        return ans;
    }
};