class Solution {
public:
    int uf[1001];
    int disjoint(int x){
        if(x == uf[x]) return x;
        return uf[x] = disjoint(uf[x]);
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        for(int i = 0 ; i <= 1000; i++){
            uf[i] = i;
        }
        vector<int> ans;
        for(int i = 0 ; i < edges.size(); i++){
            int a = edges[i][0];
            int b = edges[i][1];
            if(disjoint(a) != disjoint(b)){
                uf[disjoint(a)] = disjoint(b);
            } else{
                ans.push_back(a);
                ans.push_back(b);
            }
        }
        return ans;
    }
};