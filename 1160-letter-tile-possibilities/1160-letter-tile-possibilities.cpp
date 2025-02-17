class Solution {
public:
    bool visited[7];
    set<string> s;
    void checkCnt(string &tiles, string letters, int length, int depth){
        if(length == depth){
            s.insert(letters);
            return;
        }
        for(int i = 0 ; i < tiles.size(); i++){
            if(visited[i]) continue;
            visited[i] = true;
            checkCnt(tiles, letters + tiles[i], length + 1, depth);
            visited[i] = false;
        }
    }   
    int numTilePossibilities(string tiles) {
        for(int i = 1; i <= tiles.size(); i++){
            checkCnt(tiles, "", 0, i);
        }
        return s.size();
    }
};