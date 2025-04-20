class Solution {
public:
    int sameCnt[1001];
    int numRabbits(vector<int>& answers) {
        for(int i = 0 ; i < answers.size(); i++){
            sameCnt[answers[i]]++;
        }
        int ans = sameCnt[0];
        for(int i = 1 ; i < 1000; i++){
            if(sameCnt[i] == 0) continue;
            ans += (i+1)*((sameCnt[i] - 1)/ (i + 1) + 1);
        }
        return ans;
    }
};