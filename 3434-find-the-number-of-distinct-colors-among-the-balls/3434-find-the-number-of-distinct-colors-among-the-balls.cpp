class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> colorCnt;
        unordered_map<int, int> curColor;
        vector<int> ans;
        int colornum = 0;
        for(int i = 0 ; i < queries.size(); i++){
            int idx = queries[i][0];
            int color = queries[i][1];
            if(curColor[idx] == color){
                ans.push_back(colornum);
                continue;
            }
            if (colorCnt[curColor[idx]] > 0){
                colorCnt[curColor[idx]]--;
                if(colorCnt[curColor[idx]] == 0){
                    colornum--;
                }
            }
            if(colorCnt[color] == 0){
                colornum++;
            }
            curColor[idx] = color;
            colorCnt[color]++;
             
            ans.push_back(colornum);
        }
        return ans;
    }
};