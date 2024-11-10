struct _bit{
    int cnt[32] = {0};
    void add(int num){
        int c = 0;
        while(num){
            if (num%2){
                cnt[c]++;
            }
            num /= 2;
            c++;
        }
    }
    void sub(int num){
        int c = 0;
        while(num){
            if (num %2){
                cnt[c]--;
            }
            num /= 2;
            c++;
        }
    }
    int getNum(){
        long long pow = 1;
        long long num = 0;
        for(int i = 0 ; i < 31; i++){
            int x = 0;
            if(cnt[i] > 0){
                x = 1;
            }
            num += pow * x;
            pow *= 2;
        }
        return num;
    }
};


class Solution {
public:
    _bit b;
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int res = nums.size()+1;
        
        int l = 0;
        int r = 0;
        if (k == 0 ) return 1;
        while(r < nums.size() && l <= r){
            int num = b.getNum();
            if(num >= k){
                res = min(res, r - l);
                b.sub(nums[l++]);
            } else {
                b.add(nums[r++]);
            }
        }
        int num = b.getNum();
        if(num >= k){
            res = min(res, r - l);
        } 
        while(l < nums.size()){
            num = b.getNum();
            if(num >= k){
                res = min(res, r - l);
                b.sub(nums[l++]);
            } else {
                break;
            }
        }
        
        if (res == nums.size() + 1) return -1;
        return res;
    }
};