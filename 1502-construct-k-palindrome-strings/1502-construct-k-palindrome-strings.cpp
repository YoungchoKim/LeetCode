class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.size() < k) return false;
        int cnt[128];
        for(char c: s){
            cnt[c]++;
        }
        int odd = 0;
        for(int i = 'a'; i <= 'z'; i++){
            odd += cnt[i] & 1;
        }
        return odd <= k;
    }
};