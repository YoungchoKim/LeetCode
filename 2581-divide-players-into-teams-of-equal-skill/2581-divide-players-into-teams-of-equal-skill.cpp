class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        unordered_map<int, int> m;
        sort(skill.begin(), skill.end());
        int total = 0;
        int N = skill.size();
        for(int i = 0 ; i < N; i++){
            m[skill[i]]++;
            total += skill[i];
        }
        int eachSum = total / (N / 2);
        long long res = 0;
        for(int i = 0 ; i < N/2; i++){
            int a = skill[i];
            int b = eachSum - a;
            if (m[a] == 0) return -1;
            m[a]--;
            if (m[b] == 0) return -1;
            m[b]--;
            res += a*b;
        }
        return res;

    }
};