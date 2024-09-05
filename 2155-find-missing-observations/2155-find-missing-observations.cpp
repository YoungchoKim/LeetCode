class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        vector<int> ans;
        int m = rolls.size();
        int totalSum = (m + n) * mean;
        for(int i = 0 ; i < m; i++){
            totalSum -= rolls[i];
        }
        if(totalSum < n || totalSum > n*6) return ans;
        for(int i = 0 ; i < n; i++){
            ans.push_back(totalSum/n);
            if (totalSum % n != 0){
                ans[i] += 1;
                totalSum--;
            }
        }
        return ans;
    }
};