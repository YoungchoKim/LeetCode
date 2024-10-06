class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        string t;
        if (sentence1.size() < sentence2.size()){
            t = sentence1;
            sentence1 = sentence2;
            sentence2 = t;
        }
        int lastSpace = -1;
        int i = 0;
        for( ; i < sentence2.size(); i++){
            if(sentence2[i] == sentence1[i] && sentence2[i] == ' '){
                lastSpace = i;
            }
            if (sentence1[i] != sentence2[i]) break;
        }
        if (i == sentence2.size() && sentence1[i] == ' ') return true;
        int s1_len = sentence1.size();
        int s2_len = sentence2.size();
        int before_idx = sentence1.size() - (s2_len - lastSpace);
        if (before_idx >= 0 && sentence1[before_idx] != ' ') return false;
        for(i = lastSpace+1; i < s2_len; i++){
            int s1_idx = sentence1.size() - (s2_len - i);
            if(s1_idx >= s1_len) return false;
            if(sentence1[s1_idx] != sentence2[i]) return false;
        }
        return true;
    }
};