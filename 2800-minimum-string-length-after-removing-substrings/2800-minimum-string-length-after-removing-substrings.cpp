class Solution {
public:
    int minLength(string s) {
        int ans = s.size();
        for(int i = 0 ; i < s.size(); i++){
            if (s.substr(i, 2).compare("AB") == 0){
                ans = min(ans, minLength(s.substr(0, i) + s.substr(i+2)));
                break;
            } else if (s.substr(i, 2).compare("CD") == 0){
                ans = min(ans, minLength(s.substr(0, i) + s.substr(i+2)));
                break;
            }
        }
        return ans;
    }
};