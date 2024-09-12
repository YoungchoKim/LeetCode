class Solution {
public:
    bool allow[256];
    int countConsistentStrings(string allowed, vector<string>& words) {
        for(int i = 0 ; i < allowed.size(); i++){
            allow[allowed[i]] = true;
        }
        int ans = 0;
        for(int i = 0 ; i < words.size(); i++){
            bool success = true;
            for(int j = 0; j < words[i].size(); j++){
                if (!allow[words[i][j]]){
                    success = false;
                    break;
                }
            }
            if (success){
                ans++;
            }
        }
        return ans;
    }
};