class Solution {
public:
    set<int> s;
    vector<int> ans;
    bool visited[100] = {false,};
    void combi(vector<int>& digits, int depth, int num){
        if(depth == 3){
            if(num % 2 == 0){
                s.insert(num);
            }
            return;
        }
        for(int i = 0 ; i < digits.size(); i++){
            if(visited[i]) continue;
            int n = num * 10 + digits[i];
            if(n == 0) continue;
            visited[i] = true;
            combi(digits, depth+1, n);
            visited[i] = false;
        }
    }
    vector<int> findEvenNumbers(vector<int>& digits) {
        sort(digits.begin(), digits.end());
        combi(digits, 0, 0);
        for (int num : s){
            ans.push_back(num);
        }
        return ans;
    }
};