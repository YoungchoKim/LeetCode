class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int> ans;
        int N = code.size();
        for(int i = 0 ; i < N; i++){
            int sum = 0;
            for(int j = 1; j <= abs(k); j++){
                int idx;
                if (k > 0){
                    idx = (i + j) % N;
                } else if(k < 0) {
                    idx = (i - j + N) % N;
                } else{
                    break;
                }
                sum += code[idx];
            }
            ans.push_back(sum);
        }
        return ans;
    }
};