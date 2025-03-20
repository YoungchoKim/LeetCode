class Solution {
public:
    int uf[100001];
    int groupWeight[100001];
    int disjointSet(int x){
        if(x == uf[x]) return x;
        return uf[x] = disjointSet(uf[x]);
    }
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        for(int i = 0 ; i < n ;i++){
            uf[i] = i;
            groupWeight[i] = 0x0FFFFFFF;
        }
        for(int i = 0; i < edges.size(); i++){
            int a = edges[i][0];
            int b = edges[i][1];
            int w = edges[i][2];
            int ww = groupWeight[disjointSet(a)] & groupWeight[disjointSet(b)] & w;
            uf[disjointSet(a)] = disjointSet(b);
            groupWeight[disjointSet(a)] = ww;
        }
        vector<int> ans;
        for(int i = 0 ; i < query.size(); i++){
            int s = query[i][0];
            int e = query[i][1];
            if(disjointSet(s) == disjointSet(e)){
                ans.push_back(groupWeight[disjointSet(s)]);
            }else{
                ans.push_back(-1);
            }
        }
        return ans;
    }
};