class Solution {
public:
    int minimumDeletions(string s) {
        int ans = 0;
        int b_cnt = 0;
        for(int i = 0 ; i < s.size(); i++){
            if(s[i] == 'b'){
                b_cnt++;
            } else if (b_cnt > 0 && s[i] == 'a'){
                ans++;
                b_cnt--;
            }
        }
        return ans;
    }
};