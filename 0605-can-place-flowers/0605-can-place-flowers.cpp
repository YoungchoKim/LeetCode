class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int zeroCnt = 0;
        int ans = 0;
        int N = flowerbed.size();
        if (N == 1 && flowerbed[0] == 0) return true;
        
        if (N >= 2 && flowerbed[0] == 0 && flowerbed[1] == 0){
            flowerbed[0] = 1;
            ans++;
        }
        if (N >= 2 && flowerbed[N-1] == 0 && flowerbed[N-2] == 0){
            flowerbed[N-1] = 1;
            ans++;
        }

        for(int i = 0 ; i < flowerbed.size(); i++){
            if(flowerbed[i]){
                zeroCnt = 0;
            } else {
                zeroCnt++;
            }
            
            if (zeroCnt >= 3){
                ans++;
                zeroCnt = 1;
            }
        }
        if (ans >= n)
            return true;
        return false;
    }
};