class Solution {
    int cnt[256] = {0};
public:
    bool all_include(){
        return cnt['a'] > 0 && cnt['b'] > 0 && cnt['c'] > 0;
    }
    int numberOfSubstrings(string s) {
        int l = 0;
        int r = 0;
        int ans = 0;
        while(r < s.size()){
            cnt[s[r]]++;

            while(all_include() && l < r){
                ans += s.size() - r;
                cnt[s[l]]--;
                l++;
            }

            r++;

        }
        return ans;
    }
};