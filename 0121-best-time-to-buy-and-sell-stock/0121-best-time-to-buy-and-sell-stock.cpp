class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int minValue = 1234567890;
        for(int i = 0 ; i <prices.size(); i++){
            if(prices[i] - minValue > 0){
                ans = max(ans, prices[i] - minValue);
            }
            if(minValue > prices[i]){
                minValue = prices[i];
            }
        }
        return ans;
    }
};