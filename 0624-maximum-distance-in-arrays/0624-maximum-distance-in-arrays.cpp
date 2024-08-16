struct number{
    int idx;
    int value;
};
class Solution {
public:
    int ABS(int x){
        return x < 0 ? -x: x;
    }
    int maxDistance(vector<vector<int>>& arrays) {
        number minNum = {0, 10001};
        number secondMinNum = {0, 10001};

        number maxNum = {0, -10001};
        number secondMaxNum = {0, -10001};

        for(int i = 0 ; i < arrays.size(); i++){
            int minValue = arrays[i][0];
            int maxValue = arrays[i][arrays[i].size() - 1];
            if (minValue <minNum.value){
                secondMinNum.value = minNum.value;
                secondMinNum.idx = minNum.idx;
                minNum.value = minValue;
                minNum.idx = i;
            } else if (minValue < secondMinNum.value){
                secondMinNum.value = minValue;
                secondMinNum.idx = i;
            }

            if (maxValue > maxNum.value){
                secondMaxNum.value = maxNum.value;
                secondMaxNum.idx = maxNum.idx;
                maxNum.value = maxValue;
                maxNum.idx = i;
            } else if (maxValue > secondMaxNum.value){
                secondMaxNum.value = maxValue;
                secondMaxNum.idx = i;
            }
        }
        if (maxNum.idx != minNum.idx){
            return ABS(maxNum.value - minNum.value);
        } else{
            int a = ABS(maxNum.value - secondMinNum.value);
            int b = ABS(secondMaxNum.value - minNum.value);
            return a > b ? a : b;
        }

    }
};