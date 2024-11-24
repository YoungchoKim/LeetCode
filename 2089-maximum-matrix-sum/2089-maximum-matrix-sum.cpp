class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int cnt = 0;
        int minValue = 100001;
        long long sum = 0;
        bool isZero = false;
        for(int i = 0 ; i < matrix.size(); i++){
            for(int j = 0 ; j < matrix[0].size(); j++){
                sum += abs(matrix[i][j]);
                if(matrix[i][j] < 0){
                    cnt++;
                }
                minValue = min(minValue, abs(matrix[i][j]));
                if(matrix[i][j] == 0){
                    isZero = true;
                }
            }
        }
        if(!isZero && (cnt &1)){
            sum -= minValue*2;
        }
        return sum;
    }
};