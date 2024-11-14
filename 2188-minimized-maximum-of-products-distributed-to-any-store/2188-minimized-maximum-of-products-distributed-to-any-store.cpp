class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int ans = quantities[0];
        int l = 1;
        int r = 100000;
        while(l <= r){
            int mid = (l + r) / 2;
            int cnt = 0;
            for(int i = 0 ; i < quantities.size(); i++){
                cnt += quantities[i] / mid;
                if (quantities[i] % mid != 0){
                    cnt++;
                }
            }
            if (cnt <= n){
                r = mid - 1;
                ans = mid;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};