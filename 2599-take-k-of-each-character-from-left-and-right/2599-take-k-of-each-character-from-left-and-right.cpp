class Solution {
public:
    int cnt[256];
    int takeCharacters(string s, int k) {
        int N = s.size();
        int ans= -1;
        int i;
        for(i = 0 ; i < N; i++){
            cnt[s[i]]++;
            if(cnt['a'] >= k && cnt['b'] >= k && cnt['c'] >= k){
                ans = i+1;
                break;
            }
        }
        if(ans == -1) return -1;
        int r = N -1;
        while(i>=0){
            cnt[s[i]]--;
            if(cnt['a'] >= k && cnt['b'] >= k && cnt['c'] >= k){
                ans = min(ans,i + N - r - 1);
                i--;
                continue;
            }
            while (r >= 0 && (cnt['a'] < k || cnt['b'] < k || cnt['c'] < k)){
                cnt[s[r]]++;
                r--;
            }
            if(cnt['a'] >= k && cnt['b'] >= k && cnt['c'] >= k){
                ans = min(ans, i + 1 + N - r -1);
            }

            i--;
        }
        
        return ans;
    }
};