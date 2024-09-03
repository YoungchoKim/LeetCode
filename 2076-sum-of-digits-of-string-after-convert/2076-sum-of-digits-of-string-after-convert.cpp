class Solution {
public:
    int getSum(string s){
        int sum = 0;
        for(int i = 0 ; i < s.size(); i++){
            sum += s[i] - '0';
        }
        return sum;
    }
    int getLucky(string s, int k) {
        string num = "";
        for(int i = 0 ; i < s.size(); i++){
            num += to_string(s[i] - 'a' + 1);
        }
        int transform;
        while(k--){
            transform = getSum(num);
            num = to_string(transform);
        }
        
        return transform;
    }
};