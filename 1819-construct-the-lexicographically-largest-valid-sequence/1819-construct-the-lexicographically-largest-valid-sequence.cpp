class Solution {
public:
    int nextIdx(vector<int>& ans){
        for(int i = 0 ; i < ans.size(); i++){
            if(ans[i] == -1)
                return i;
        }
        return -1;
    }
    int visited[21];
    bool dfs(int N, vector<int>& ans){
        bool success = true;
        for(int i = 0 ; i < ans.size(); i++){
            if(ans[i] == -1){
                success = false;
                break;
            }
        }

        if(success){
            return true;
        }
        for(int i = N; i > 0; i--){
            if(visited[i]){
                continue;
            }
            visited[i] = true;
            int idx = nextIdx(ans);
            ans[idx] = i;
            if(i != 1){
                if(idx+i >= (2*N-1)  || ans[idx+i] != -1){
                    ans[idx] = -1;
                    visited[i] = false;
                    continue;
                } else{
                    ans[idx+i] = i;
                }
            }
            if(dfs(N, ans)){
                return true;
            }
            ans[idx] = -1;
            if(i != 1)
                ans[idx+i]= -1;
            visited[i] = false;
                   
        }
        return false;
    }
    vector<int> constructDistancedSequence(int n) {
        vector<int> ans;
        for(int i = 0; i < ((n << 1)-1) ; i++){
            ans.push_back(-1);
        }
        dfs(n, ans);
        return ans;   
    }
};