class Solution {
public:
    queue<int> que;
    set<string> supply;
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int N = recipes.size();
        
        for(int i = 0 ; i < N; i++){
            que.push(i);
        }
        for(int i = 0 ; i < supplies.size(); i++){
            supply.insert(supplies[i]);
        }
        vector<string> ans;
        int cnt = 0;
        while(!que.empty() && cnt < N){
            int idx = que.front();
            que.pop();
            bool success = true;
            for(int i = 0; i < ingredients[idx].size(); i++){
                if(supply.find(ingredients[idx][i]) == supply.end()){
                    success = false;
                    break;
                }
            }
            if(success){
                supply.insert(recipes[idx]);
                ans.push_back(recipes[idx]);
                cnt = -1;
                N--;
            } else{
                que.push(idx);
            }
            cnt++;
        }
        return ans;
    }
};