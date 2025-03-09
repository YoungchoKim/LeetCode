class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int N = colors.size();
        for(int i = 0 ; i < N; i++){
            colors.push_back(colors[i]);
        }
        int cnt = 1;
        int cur = colors[0] ^ 1;
        int ans = 0;
        for(int i = 1; i < k; i++){
            if(cur == colors[i]){
                cnt++;
            }else{
                cnt = 1;
            }
            cur = colors[i] ^ 1;
        }
        if(cnt >= k){
            ans++;
        }
        for(int i = k; i < N + k - 1; i++){
            if(cur == colors[i]){
                cnt++;
            }else{
                cnt = 1;
            }
            if(cnt >= k){
                ans++;
            }
            cur = colors[i] ^ 1;
        }
        return ans;
    }
};