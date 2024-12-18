class Solution {
public:
    vector<int> st;
    vector<int> finalPrices(vector<int>& prices) {
        for(int i = prices.size() - 1; i >= 0 ; i--){
            while(st.size() != 0 && st.back() > prices[i]){
                st.pop_back();
            }
            if(st.size() == 0){
                st.push_back(prices[i]);
            } else{
                prices[i] -= st.back();
                st.push_back(prices[i] + st.back());
            }
        }
        return prices;
    }
};