class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        vector<vector<char>> rotateBox;
        for(int i = 0 ; i< box.size(); i++){
            int r = box[0].size() - 1;
            int l = r;
            while(l >= 0){
                if(box[i][l] == '#'){
                    box[i][r] = box[i][l];
                    if(l != r){
                        box[i][l] = '.';
                    }
                    r--;
                } else if(box[i][l] == '*'){
                    r = l - 1;
                }
                l--;
            }

        }
        int R = box.size();
        int C = box[0].size();
        for(int j=0; j < C; j++){
            rotateBox.push_back(vector<char>());
            for(int i = 0; i < R; i++){
                rotateBox[j].push_back(box[R-i-1][j]);
            }
        }
        
        


        return rotateBox;
    }
};