class Solution {
public:
    bool isPrefixAndSuffix(string str1, string str2){
        if(str1.size() > str2.size()) return false;
        for(int i = 0 ; i < str1.size(); i++){
            if(str1[i] != str2[i])return false;
            if(str1[i] != str2[str2.size() - str1.size() + i]) return false;
        }
        return true;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int ans = 0;
        for(int i = 0 ; i < words.size(); i++){
            for(int j = i + 1 ; j < words.size(); j++){
                if(isPrefixAndSuffix(words[i], words[j])){
                    ans++;
                }
            }
        }
        return ans;
    }
};