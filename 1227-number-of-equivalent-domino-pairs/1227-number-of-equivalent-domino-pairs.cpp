class Solution {
public:
    unordered_map<int, long long> cnt;
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        for(int i = 0 ; i < dominoes.size() ; i++){
            int a = dominoes[i][0];
            int b = dominoes[i][1];
            if(a > b){
                int t = a;
                a = b;
                b = t;
            }
            cnt[a*10 + b]++;
        }
        int ans = 0;
        for(auto iter = cnt.begin(); iter != cnt.end(); iter++){
            ans += (iter->second * (iter->second-1)) / 2;
        }
        return ans;
    }
};