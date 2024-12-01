class Solution {
public:
    int number[4004];
    bool checkIfExist(vector<int>& arr) {
        for(int i = 0 ; i < arr.size(); i++){
            if (arr[i] & 1) {
                if(number[(arr[i] << 1) + 2000]){
                    return true;
                }
            } else{
                if(number[(arr[i] << 1) + 2000]){
                    return true;
                }
                if(number[(arr[i] >> 1) + 2000]){
                    return true;
                }
            }
            number[arr[i] + 2000] = true;
        }
        return false;
    }
};