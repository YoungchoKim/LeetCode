class Solution {
public:
    int maximumLength(string s) {
        int ans = -1;
        int l = 1;
        int r = s.size()-2;
        while(l <= r){
            int mid = (l + r) / 2;
            cout << l << " " << mid << " " << r << endl;
            bool success = false;
            for(char i = 'a'; i <= 'z'; i++){
                string ss = "";
                for(int j = 0 ; j < mid; j++){
                    ss += i;
                }
                int k = 0;
                int specialCnt = 0;
                for(int j = 0; j < s.size(); j++){
                    if(s[j] == ss[k]){
                        k++;
                    } else{
                        k = 0;
                    }
                    if(k == mid){
                        k--;
                        specialCnt++;
                        if(specialCnt >= 3){
                            success = true;
                            break;
                        }
                    }
                    if(success) break;
                }
                if(success) break;
            }
            if(success){
                l = mid + 1;
                ans = mid;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
};