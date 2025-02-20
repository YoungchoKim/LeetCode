class Solution {
public:
    int makeNum(string s){
        int num = 0;
        for(int i = 0 ; i < s.size(); i++){
            num *= 2;
            num += s[i] - '0';
        }
        return num;
    }
    string makeStr(int num, int length){
        string res = "";
        for(int i = 0 ; i < length; i++){
            res = string(1, '0'+(num %2)) + res;
            num /= 2;
        }
        return res;
    }
    bool set[1<<16];
    string findDifferentBinaryString(vector<string>& nums) {
        int length = nums[0].size();
        for(int i = 0 ; i < nums.size(); i++){
            set[makeNum(nums[i])] = true;
        }
        for(int i = 0 ; i < (1 << 16); i++){
            if(set[i]){
                continue;
            }
            return makeStr(i, length);
        }
        return "";
    }
};