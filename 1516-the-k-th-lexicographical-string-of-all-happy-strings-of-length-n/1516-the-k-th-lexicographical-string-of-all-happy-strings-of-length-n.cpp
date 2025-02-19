class Solution {
public:
    char c[3] = {'a', 'b', 'c'};
    int cnt;
    string getHappyString(int n, int k, int depth = 0, string res = "") {
        if(n == depth){
            cnt++;
            if(cnt == k){
                return res;
            }
            return "";
        }
        for(int i = 0 ; i < 3; i++){
            if(depth != 0 && res[depth-1] == c[i]){
                continue;
            }
            string ans = getHappyString(n, k, depth + 1, res + c[i]);
            if(ans.size() != 0){
                return ans;
            }
        }
        return "";
    }
};