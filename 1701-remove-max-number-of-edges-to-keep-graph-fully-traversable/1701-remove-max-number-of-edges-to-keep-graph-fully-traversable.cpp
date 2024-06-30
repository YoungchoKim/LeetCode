
vector<vector<int>> edgesType1;
vector<vector<int>> edgesType2;

bool cmp1(int a, int b){
    return edgesType1[a][0] > edgesType1[b][0];
}
bool cmp2(int a, int b){
    return edgesType2[a][0] > edgesType2[b][0];
}
class Solution {
public:
    int u1[100001];
    int sortArray1[100001];
    int u2[100001];
    int sortArray2[100001];
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
            sortArray1[i] = i;
            sortArray2[i] = i;
            if(edges[i][0] == 1){
                edgesType1.push_back(edges[i]);
            } else if (edges[i][0] == 2){
                edgesType2.push_back(edges[i]);
            } else{
                edgesType1.push_back(edges[i]);
                edgesType2.push_back(edges[i]);
            }
        }
        sort(sortArray1, sortArray1 + edgesType1.size(), cmp1);
        sort(sortArray2, sortArray2 + edgesType2.size(), cmp2);
        for(int i = 0 ; i < edgesType1.size(); i++){
            int idx = sortArray1[i];
            cout<< edgesType1[idx][0] << " " <<  edgesType1[idx][1] << " " << edgesType1[idx][2] << endl;
        } 

        int type3 = 0;
        int cnt = 0;
        for (int i = 0 ; i < edgesType1.size(); i++) {
            int idx = sortArray1[i];
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
        cout << "cnt: " << cnt << endl;
        if (cnt != n-1) return -1;
        cout << "type3: " << type3 << endl;
        cnt = 0;
        for (int i = 0 ; i < edgesType2.size(); i++) {
            int idx = sortArray2[i];
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
        cout << "cnt: " << cnt << endl;
        if (cnt != n-1) return -1;
        cout << "end" << endl;

        return edges.size() - (n - 1) - (n - 1) + type3;
    }
};