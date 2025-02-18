class Solution {
public:
    string smallestNumber(string pattern) {
        char num[10] = {0};
        num[0] = '1';
        for(int i = 1; i <= pattern.size(); i++ ){
            num[i] = '1'+i;
            int j = i;
            while(j > 0 && pattern[j-1] == 'D'){
                char t = num[j];
                num[j] = num[j-1];
                num[j-1] = t;
                j--;
            }
        }
        string ans = "";
        ans += num[0];
        for(int i = 1; i <= pattern.size(); i++){
            ans += num[i];
        }
        return ans;
    }
};