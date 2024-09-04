class Solution {
public:
    set<pair<int, int>> s;
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int ans = 0;
        for(int i = 0 ; i < obstacles.size(); i++){
            int x = obstacles[i][0];
            int y = obstacles[i][1];
            s.insert({y, x});
        }
        int dir = 0;
        int dy[] = {1, 0, -1, 0};
        int dx[] = {0, 1, 0, -1};
        int y = 0;
        int x = 0;
        for(int i = 0 ; i < commands.size(); i++){
            if(commands[i] == -1){
                dir = (dir + 1) %4;
                continue;
            } else if(commands[i] == -2){
                dir = (dir + 3) %4;
                continue;
            } 
            for(int j = 0 ; j < commands[i]; j++){
                int ny = y + dy[dir];
                int nx = x + dx[dir];
                if (ny < -30000 || ny > 30000 || nx < -30000 || nx > 30000) continue;
                if (s.find({ny, nx}) != s.end()){
                    continue;
                }

                y = ny;
                x = nx;
                ans = max(ans, (y*y) + (x * x));
            }
        }
        return ans;
        
    }
};