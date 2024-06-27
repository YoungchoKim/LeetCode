class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int cnt[100001] = {0};
        for(int i = 0 ; i < edges.size(); i++){
            int a = edges[i][0];
            int b = edges[i][1];
            cnt[a]++;
            cnt[b]++;
            if (cnt[a] >= 2) return a;
            if (cnt[b] >= 2) return b;
        }
        return 0;
    }
};