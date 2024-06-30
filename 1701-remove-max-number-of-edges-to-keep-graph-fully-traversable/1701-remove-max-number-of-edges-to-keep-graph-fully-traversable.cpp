

class Solution {
public:
    int u1[100001];
    int u2[100001];
    
    vector<vector<int>> edgesType1;
    vector<vector<int>> edgesType2;
    static bool cmp1(vector<int> &a, vector<int> &b){
        return a[0] > b[0];
    }
    static bool cmp2(vector<int> &a, vector<int> &b){
        return a[0] > b[0];
    }
    int disjoint(int* u, int x){
        if(u[x] == x) return x;
        return u[x] = disjoint(u, u[x]);
    }
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        edgesType1.clear();
        edgesType2.clear();
        int edgeSize = edges.size();
        for(int i = 1; i <= n; i++){
            u1[i] = i;
            u2[i] = i;
        }
        for(int i = 0; i < edges.size(); i++){
            if(edges[i][0] == 1){
                edgesType1.push_back(edges[i]);
            } else if (edges[i][0] == 2){
                edgesType2.push_back(edges[i]);
            } else{
                edgesType1.push_back(edges[i]);
                edgesType2.push_back(edges[i]);
            }
        }
        sort(edgesType1.begin(), edgesType1.end(), cmp1);
        sort(edgesType2.begin(), edgesType2.end(), cmp2);

        int type3 = 0;
        int cnt = 0;
        for (int idx = 0 ; idx < edgesType1.size(); idx++) {
            int type = edgesType1[idx][0];
            int a = edgesType1[idx][1];
            int b = edgesType1[idx][2];
            if(disjoint(u1, a) == disjoint(u1, b)){
                continue;
            }
            cnt++; 
            u1[disjoint(u1, a)] = disjoint(u1, b);
            if (type == 3){
                type3 += 1;
            }
            if (cnt == n -1) break;
        }
        if (cnt != n-1) return -1;
        cnt = 0;
        for (int idx = 0 ; idx < edgesType2.size(); idx++) {
            int type = edgesType2[idx][0];
            int a = edgesType2[idx][1];
            int b = edgesType2[idx][2];
            if(disjoint(u2, a) == disjoint(u2, b)){
                continue;
            }
            cnt++; 
            u2[disjoint(u2, a)] = disjoint(u2, b);
            if (cnt == n -1) break;
        }
        if (cnt != n-1) return -1;

        return edges.size() - (n - 1) - (n - 1) + type3;
    }
};