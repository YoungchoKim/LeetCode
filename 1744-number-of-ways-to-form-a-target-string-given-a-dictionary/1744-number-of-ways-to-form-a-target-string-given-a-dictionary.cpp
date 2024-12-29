class Solution {
public:
    int dict[1001][128];
    int memo[1001][1001];
    int dictN;
    long long getCnt(string& target, int targetIdx, int dictIdx){
        if(target.size() == targetIdx) return 1;
        if(dictIdx >= dictN) return 0;
        if(memo[dictIdx][targetIdx] != -1) return memo[dictIdx][targetIdx];
        long long ret = 0;
        for(int i = dictIdx; i < dictN - (target.size() - targetIdx - 1); i++){
            if(dict[i][target[targetIdx]] == 0) continue;
            ret += getCnt(target, targetIdx+1, i + 1) * dict[i][target[targetIdx]] % 1000000007;
            ret %= 1000000007;
        }
        return memo[dictIdx][targetIdx] = ret;
    }
    int numWays(vector<string>& words, string target) {
        dictN = words[0].size();
        memset(memo, -1, sizeof(memo));
        if(dictN < target.size()) return 0;
        for(int i = 0 ; i < words.size(); i++){
            for(int j = 0 ; j < dictN; j++){
                dict[j][words[i][j]]++;
            }
        }
        return getCnt(target, 0, 0);
    }
};