class Solution {
public:
    int uf[51];
    int edgeCnt[51] = {0};
    int groupCnt[51] = {0};
    int disjointSet(int x){
        if (x == uf[x]) return x;
        return uf[x] = disjointSet(uf[x]);
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        if (n == 1) return 1;
        set<int> ans;
        for(int i = 0 ; i < n; i++){
            uf[i] = i;
            groupCnt[i] = 1;
        }
        for(int i = 0 ; i < edges.size(); i++){
            int a = edges[i][0];
            int b = edges[i][1];
            if(disjointSet(a) != disjointSet(b)){
                groupCnt[disjointSet(b)] += groupCnt[disjointSet(a)];
                groupCnt[disjointSet(a)] = 0;
                edgeCnt[disjointSet(b)] += edgeCnt[disjointSet(a)];
                edgeCnt[disjointSet(b)] += 1;
                edgeCnt[disjointSet(a)] = 0;
                uf[disjointSet(a)] = disjointSet(b);
            }else{
                edgeCnt[disjointSet(b)] += 1;
            }
        }
        for(int i = 0 ; i < n; i++){
            if(ans.find(disjointSet(i)) == ans.end()){
                ans.insert(disjointSet(i));
            }
        }
        cout << "answer size: " << ans.size() << endl;
        vector<int> removeList;
        for(auto idx : ans){
            int n = groupCnt[disjointSet(idx)];
            int e = edgeCnt[disjointSet(idx)];
            cout << n << " " << e << endl;
            if((n*(n-1)/2) != e){
                removeList.push_back(idx);
            }
        }
        for(int i = 0 ; i < removeList.size(); i++){
            ans.erase(removeList[i]);
        }
        return ans.size();
    }
};