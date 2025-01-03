class Solution {
public:

    bool canMakeSubsequence(string str1, string str2) {
        int j = 0;
        for(int i = 0 ; i < str1.size(); i++){
            char next = str1[i] == 'z' ? 'a' : str1[i] + 1;
            if(j < str2.size() && (str1[i] == str2[j] || str2[j] == next)){
                j++;
            }
        }
        if (j >= str2.size()) return true;
        return false;
    }
};