class Solution {
public:
    int str_cnt[256];
    string compressedString(string word) {
        int cnt = 0;
        char beforeChar = 'a'-1;
        string res = "";
        for(char c : word) {
            if(c != beforeChar){
                int a = cnt / 9;
                for(int i = 0 ; i < a; i++){
                    res += "9" + string(1, beforeChar);
                }
                int b = cnt % 9;
                if (b > 0){
                    res += to_string(b) + string(1, beforeChar);
                }
                cnt = 0;
            }
            cnt++;
            beforeChar = c;
        }
        int a = cnt / 9;
        for(int i = 0 ; i < a; i++){
            res += "9" + string(1, beforeChar);
        }
        int b = cnt % 9;
        if (b > 0){
            res += to_string(b) + string(1, beforeChar);
        }
        
        return res;
    }
};