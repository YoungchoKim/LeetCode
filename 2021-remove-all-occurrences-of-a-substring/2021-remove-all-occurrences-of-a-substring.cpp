class Solution {
public:
    vector<char> st;
    string removeOccurrences(string s, string part) {
        for(int i = 0 ; i < s.size(); i++){
            st.push_back(s[i]);
            if(st.size() >= part.size()){
                bool success = true;
                for(int j = 0; j < part.size(); j++){
                    if(st[st.size()-j -1] != part[part.size() - j - 1]){
                        success = false;
                        break;
                    }
                }
                if(success){
                    for(int j = 0 ; j < part.size(); j++){
                        st.pop_back();
                    }
                }
            }
        }
        string ans = "";
        for(int i = 0 ; i < st.size(); i++){
            ans += st[i];
        }
        return ans;
    }
};