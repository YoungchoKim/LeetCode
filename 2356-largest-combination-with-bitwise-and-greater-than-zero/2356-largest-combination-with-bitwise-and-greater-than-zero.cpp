class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int maxCnt = 0;
        for(int i = 0 ; i < 24; i++){
            int mask = 1 << i;
            int cnt = 0;
            for(int j = 0 ; j < candidates.size(); j++){
                if((candidates[j] & mask) > 0){
                    cnt++;
                }
            }
            maxCnt = max(maxCnt, cnt);
        }
        return maxCnt;
    }
};