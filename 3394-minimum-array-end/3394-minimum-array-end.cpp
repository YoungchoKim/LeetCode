class Solution {
public:
    vector<int> xv, nv, ansv;
    long long minEnd(int n, int x) {
        n--;
        while(n){
            nv.push_back(n%2);
            n /= 2;
        }
        while(x){
            xv.push_back(x%2);
            x /= 2;
        }
        int nIdx = 0;
        for(int xIdx = 0; xIdx < xv.size(); xIdx++){
            if(xv[xIdx] == 1){
                ansv.push_back(1);
            } else{
                if(nIdx < nv.size()){
                    ansv.push_back(nv[nIdx++]);
                } else{
                    ansv.push_back(0);
                }
            }
        }
        while(nIdx < nv.size()){
            ansv.push_back(nv[nIdx++]);
        }
        long long ans = 0;
        long long pow = 1;
        for(int i = 0 ; i < ansv.size(); i++){
            ans += pow*ansv[i];
            pow *= 2;
        }

        return ans;
    }
};