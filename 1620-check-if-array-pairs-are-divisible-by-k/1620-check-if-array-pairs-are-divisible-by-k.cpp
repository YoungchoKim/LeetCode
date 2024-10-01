class Solution {
public:
    unordered_map<int, int> cnt;
    bool canArrange(vector<int>& arr, int k) {
        if (k == 1) return true;
        long long offset = k;
        while(offset < 1e9){
            offset *= k;
        }
        for(long long num : arr){
            cnt[(num + offset) % k]++;
        }
        if(cnt[0] & 1) return false;
        for(int i = 1; i < ((k+1)>>1); i++){
            if(cnt[i] != cnt[k - i]) return false;
        }
        if((k %2) == 0 && ((cnt[k/2] %2) == 1)){
            return false;
        }
        return true;
    }
};