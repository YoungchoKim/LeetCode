class Solution {
public:
    
    bool checkPowersOfThree(int n) {
        vector<int> powerSet;
        int pow = 1;
        while(pow <= n){
            powerSet.push_back(pow);
            pow *= 3;
        }
        for(int i = powerSet.size() - 1; i >= 0; i--){
            if(n > powerSet[i]){
                n -= powerSet[i];
            } else if (n < powerSet[i]){
                continue;   
            } else{
                return true;
            }
        }
        return false;
    }
};