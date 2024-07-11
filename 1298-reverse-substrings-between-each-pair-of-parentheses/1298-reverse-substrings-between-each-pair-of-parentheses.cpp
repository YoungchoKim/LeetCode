class Solution {
public:
    
    string reverseParentheses(string s) {
        string res = "";
        int mystack[2001];
        int stackIdx = 0;
        int N = s.length();
        int idx = 0;
        for(int i = 0 ; i < N; i++){
            if (s[i] == '('){
                mystack[stackIdx++] = res.length();
            } else if (s[i] == ')'){
                int popIdx = mystack[--stackIdx];
                reverse(res.begin()+popIdx, res.end());
            } else {
                res += s[i];
            }
        }
        return res;
    }
};