class Solution {
public:
    int ans = 0;
    int numTeams(vector<int>& rating) {
        int N = rating.size();
        for(int i = 1; i < N - 1; i++){
            int leftCnt1 = 0;
            int leftCnt2 = 0;
            int idx = i - 1;
            while(idx >= 0){
                if(rating[idx] < rating[i]){
                    leftCnt1++;
                }
                if(rating[idx] > rating[i]){
                    leftCnt2++;
                }
                idx--;
            }
            int rightCnt1 = 0;
            int rightCnt2 = 0;
            idx = i + 1;
            while(idx < N){
                if(rating[i] < rating[idx]){
                    rightCnt1++;
                }
                if(rating[i] > rating[idx]){
                    rightCnt2++;
                }
                idx++;
            }
            ans += leftCnt1 * rightCnt1;
            ans += leftCnt2 * rightCnt2;
        }
        return ans;
    }
};