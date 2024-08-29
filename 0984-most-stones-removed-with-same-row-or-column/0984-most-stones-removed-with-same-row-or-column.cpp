class Solution {
public:
    vector<int> cols[10000];
    vector<int> rows[10000];
    bool visited[1000];
    map<int, int> getIdx;
    void fill(int r, int c){
        int idx = getIdx[r*10000+c];
        if (visited[idx]) return;
        visited[idx] = true;
        for(int i = 0 ; i < cols[r].size(); i++){
            fill(r, cols[r][i]);
        }
        for(int i = 0 ; i < rows[c].size(); i++){
            fill(rows[c][i], c);
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        for(int i = 0 ; i < stones.size(); i++){
            int r = stones[i][0];
            int c = stones[i][1];
            cols[r].push_back(c);
            rows[c].push_back(r);
            getIdx[r*10000+c] = i;
        }
        int uni = 0;
        for(int i = 0 ; i < stones.size(); i++){
            if(visited[i]) continue;
            uni++;
            fill(stones[i][0], stones[i][1]);
        }
        return stones.size() - uni;
    }
};