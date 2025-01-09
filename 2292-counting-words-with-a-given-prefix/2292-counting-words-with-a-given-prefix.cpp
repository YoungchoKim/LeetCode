class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int ans = 0;
        for(string word : words){
            int i = 0;
            for( ; i < pref.size(); i++){
                if(pref[i] != word[i]){
                    break;
                }
            }
            if(i == pref.size()){
                ans++;
            }
        }
        return ans;
    }
};