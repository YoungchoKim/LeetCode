class Solution {
public:
    set<string> s;
    void push(long long n){
        vector<int> tmp;
        long long nn = n;
        while(nn){
            tmp.push_back(nn%10);
            nn /= 10;
        }
        sort(tmp.begin(), tmp.end(), [](long long a, long long b) -> long long {return a > b; });
        string str = "";
        for(int i = 0 ; i < tmp.size(); i++){
            str += to_string(tmp[i]);
        }
        
        s.insert(str);
    }
    void makePalindrome(int n, int k, long long curNum, int depth){
        if(depth == (n+1)/2){
            long long tmp = curNum;
            if((n%2) == 1){
                tmp /= 10;
            }
            while(tmp){
                curNum *= 10;
                curNum += tmp %10;
                tmp /= 10;
            }
            if((curNum%k) == 0){
                push(curNum);
            }
            return;
        }
        for(int i = 0; i <= 9; i++){
            if(depth == 0 && i == 0) continue;
            makePalindrome(n, k, curNum*10 + i, depth + 1);
        }
    }
    long long combi(int n, int r){
        long long ret = 1;
        int rr = r;
        while(rr){
            ret *= n;
            rr--;
            n--;
        }
        for(int i = 1; i <= r; i++){
            ret /= i;
        }
        return ret;
    }
    long long getCnt(int cnt[10], int n){
        long long ret = 1;
        for(int i = 0 ; i < 10; i++){
            if(cnt[i] == 0) continue;
            if(i == 0){
                ret *= combi(n-1, cnt[i]);
            } else{
                ret *= combi(n, cnt[i]);
            }
            n -= cnt[i];
        }
        return ret;
    }
    long long countGoodIntegers(int n, int k) {
        makePalindrome(n, k, 0, 0);
        long long ans = 0;
        for(auto vals : s){
            int cnt[10] = {0};
            for(char c : vals){
                cnt[c-'0']++;
            }
            long long ret = getCnt(cnt, n);
            ans += ret;
        }

        return ans;
    }
};