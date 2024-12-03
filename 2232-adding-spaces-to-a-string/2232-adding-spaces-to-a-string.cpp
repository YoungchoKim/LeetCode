class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int start = 0;
        int end;
        string ans = "";
        for(int i = 0 ; i < spaces.size(); i++){
            end = spaces[i];
            ans += s.substr(start, end-start);
            ans += " ";
            start = end;
        }
        ans += s.substr(start, s.size()-start);

        return ans;
    }
};