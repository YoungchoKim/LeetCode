class Solution {
public:
    bool rotateString(string s, string goal) {
        int N = s.size();
        while(N--){
            if(s.compare(goal) == 0){
                return true;
            }
            s = s + s[0];
            s = s.substr(1);
        }

        return false;
    }
};