class Solution {
public:
    int pSum[100002];

    bool isVowel(char c){
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
            return true;
        }
        return false;
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        for(int i = 0 ; i < words.size(); i++){
            pSum[i+1] = pSum[i];
            string s = words[i];
            if(isVowel(s[0]) && isVowel(s[s.size() - 1])){
                pSum[i+1]++;
            }
        }
        vector<int> ans;
        for(int i = 0 ; i < queries.size(); i++){
            ans.push_back(pSum[queries[i][1]+1] - pSum[queries[i][0]]);
        }
        return ans;
    }
};