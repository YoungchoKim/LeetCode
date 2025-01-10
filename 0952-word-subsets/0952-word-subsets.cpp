class Solution {
public:
    int charCnt[128];
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        for(string word : words2){
            int tmpCnt[128] = {0};
            for(char c : word){
                tmpCnt[c]++;
            }
            for(int i = 'a' ; i <= 'z'; i++){
                charCnt[i] = max(charCnt[i], tmpCnt[i]);
            }
        }
        vector<string> ans;
        for(string word : words1){
            int tmpCnt[128] = {0};
            for(char c : word){
                tmpCnt[c]++;
            }
            bool isSubset = true;
            for(int i = 'a' ; i <= 'z'; i++){
                if(charCnt[i] == 0) continue;
                if(tmpCnt[i] < charCnt[i]){
                    isSubset = false;
                    break;
                }
            }
            if(isSubset){
                ans.push_back(word);
            }
        }
        return ans;
    }
};