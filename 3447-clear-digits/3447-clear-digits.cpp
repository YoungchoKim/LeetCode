class Solution {
public:
    vector<char> st;
    string clearDigits(string s) {
        for(int i = 0 ; i < s.size(); i++){
            if(s[i] >= 'a' && s[i] <= 'z'){
                st.push_back(s[i]);
            }else{
                if(st.size() != 0){
                    st.pop_back();
                }
            }
        }
        string res = "";
        for(int i = 0 ; i < st.size(); i++){
            res += st[i];
        }
        return res;
    }
};