class Solution {
public:
    long long memo[200001] = {0};
    long long mostPoints(vector<vector<int>>& questions) {
        int N = questions.size();
        for(int i = N - 1; i >= 0; i--){
            int point = questions[i][0];
            int brainpower = questions[i][1];
            memo[i] = max(point + memo[i + brainpower + 1], memo[i+1]);
        }
        return memo[0];
    }
};


