class Solution {
public:
    bool isPrime[1001];
    bool primeSubOperation(vector<int>& nums) {
        for(int i = 2 ; i <= 1000; i++){
            isPrime[i] = true;
        }
        for(int i = 2; i*i <= 1000; i++){
            for(int j = 2; i*j <= 1000; j++){
                isPrime[i*j] = false;
            }
        }
        for(int i = nums[0] - 1; i >= 2; i--){
            if(isPrime[i]){
                nums[0] -= i;
                break;
            }
        }
        for(int i = 1; i < nums.size(); i++){
            for(int j = nums[i] - 1; j >= 2; j--){
                if(isPrime[j] && nums[i-1] < (nums[i] - j)){
                    nums[i] -= j;
                    break;
                }
            }
            if(nums[i-1] >= nums[i]) return false;
        }

        return true;
    }
};