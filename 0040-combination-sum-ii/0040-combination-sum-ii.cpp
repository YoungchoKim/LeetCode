class Solution {
public:
    int cnt[31];
    void dfs(vector<vector<int>>& ans, vector<int>& history, int cur, int sum, int target){
        if(sum == target){
            vector<int> tmp;
            for(int i = 0 ; i < history.size(); i++){
                tmp.push_back(history[i]);
            }
            ans.push_back(tmp);
            return;
        }
        if (sum > target) return;

        for(int i = cur; i <= target; i++){
            if(cnt[i] <= 0) continue;
            cnt[i]--;
            history.push_back(i);
            dfs(ans, history, i, sum + i, target);
            cnt[i]++;
            history.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        for(int i = 0 ; i < candidates.size(); i++){
            if (candidates[i] > 30) continue;
            cnt[candidates[i]]++;
        }
        vector<vector<int>> ans;
        vector<int> history;
        dfs(ans, history, 0, 0, target);
        return ans;
    }
};