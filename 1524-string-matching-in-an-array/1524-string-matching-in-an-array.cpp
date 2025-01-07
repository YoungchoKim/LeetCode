class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> ans;
        for(int i = 0 ; i < words.size(); i++){
            bool success = false;
            for(int j = 0; j < words.size(); j++){
                if(i == j) continue;
                for(int k = 0; k < words[j].size(); k++){
                    int l = 0;
                    for(; l < words[i].size(); l++){
                        if(words[j][k+l] != words[i][l]) break;
                    }
                    if(l == words[i].size()){
                        ans.push_back(words[i]);
                        success = true;
                        break;
                    }
                }
                if(success) break;
            }
        }
        return ans;
    }
};