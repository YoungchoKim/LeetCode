class Solution {
public:
    long long minCost[26][26];
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        for(int i = 0; i < 26; i++){
            for(int j = 0 ; j < 26; j++){
                minCost[i][j] = 1234567890;
            }
        }

        for(int i = 0 ; i < original.size(); i++){
            int a = original[i] -'a';
            int b = changed[i] - 'a';
            if (minCost[a][b] > cost[i]){
                minCost[a][b] = cost[i];
            }
        }

        for(int k = 0 ; k < 26; k++){
            for(int i = 0 ; i < 26; i++){
                if (k == i) continue;
                for(int j = 0 ; j < 26; j++){
                    if(k == j || i == j) continue;
                    if (minCost[i][j] <= minCost[i][k] + minCost[k][j]){
                        continue;
                    }
                    minCost[i][j] = minCost[i][k] + minCost[k][j];
                }
            }
        }
        long long ans = 0;
        for(int i = 0 ; i < source.size(); i++){
            int a = source[i] - 'a';
            int b = target[i] - 'a';
            if (a == b) continue;
            if(minCost[a][b] == 1234567890) return -1;
            ans += minCost[a][b];
        }
        return ans;
    }
};