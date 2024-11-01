class Solution {
public:
    string makeFancyString(string s) {
        string ss = string(1,s[0]);
        int repeat_cnt = 1;
        char before_char = s[0];
        for(int i = 1 ;  i < s.size(); i++){
            if (before_char == s[i]){
                repeat_cnt++;
                if(repeat_cnt >= 3) continue;
            } else {
                repeat_cnt = 1;
            }
            ss += s[i];
            before_char = s[i];
        }
        return ss;
    }
};