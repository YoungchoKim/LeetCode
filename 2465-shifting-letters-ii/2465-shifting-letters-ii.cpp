class Solution {
public:
    int pSum[500001];
    int fb[2] = {25, 1};
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        for(int i = 0 ; i < shifts.size(); i++){
            int start = shifts[i][0];
            int end = shifts[i][1];
            int dir = shifts[i][2];
            pSum[start] += fb[dir];
            pSum[start] %= 26;
            pSum[end+1] += fb[dir ^ 1];
            pSum[end+1] %= 26;
            
        }

        string ans = "";
        for(int i = 0 ; i < s.size(); i++){
            pSum[i+1] += pSum[i];
            pSum[i] %= 26;
            unsigned char c = s[i] + pSum[i];
            if(c > 'z') c = 'a' + (c - 'z') - 1;
            if(c < 'a') c = 'z' - ('a' - c - 1);
            ans += c;
        }
        
        return ans;
    }
};