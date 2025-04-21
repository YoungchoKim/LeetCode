class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long maxV = 0;
        long long minV = 0;
        long long cur = 0;
        for(int i = 0; i < differences.size(); i++){
            cur += differences[i];
            maxV = max(maxV, cur);
            minV = min(minV, cur);
        }
        int diff1 = maxV - minV;
        int diff2 = upper - lower;
        if(diff1 > diff2){
            return 0;
        } else{
            return diff2 - diff1 + 1;
        }
    }
};