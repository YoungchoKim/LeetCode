class Solution {
public:
    #define MOD 1000000007
    int numOfSubarrays(vector<int>& arr) {
        
        long long prefixSum = 0;
        int evenCount = 1;
        int oddCount = 0;
        int ans = 0;
        for(int i = 0 ; i < arr.size(); i++){
            prefixSum += arr[i];

            if(prefixSum & 1){
                oddCount++;
                ans += evenCount;
            } else{
                evenCount++;
                ans += oddCount;
            }
            ans %= MOD;
        }
        return ans;
    }
};