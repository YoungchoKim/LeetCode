class Solution {
public:
    bool isPrime[1000001] = {false};
    vector<int> closestPrimes(int left, int right) {
        for(int i = 2; i <= right; i++){
            isPrime[i] = true;
        }
        for(int i = 2; i*i <= right; i++){
            if(!isPrime[i]){
                continue;
            }
            for(int j = i *2; j <= right; j += i){
                isPrime[j] = false;
            }
        }
        
        vector<int> ans;
        int beforePrime = 0;
        for(int i = left; i <= right; i++){
            if(!isPrime[i]){
                continue;    
            }
            if(ans.size() < 2){
                ans.push_back(i);
                beforePrime = i;
                continue;
            }
            else{
                if((ans[1] - ans[0]) > (i - beforePrime)){
                    ans[0] = beforePrime;
                    ans[1] = i;
                }
            }
            beforePrime = i;
        }
        if(ans.size() == 2) return ans;
        return {-1, -1};
    }
};