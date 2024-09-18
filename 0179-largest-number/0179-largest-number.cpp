class Solution {
public:
    static bool cmp(string a, string b){
        string aa = a + b;
        string bb = b + a;
        return aa < bb;
    }
    string largestNumber(vector<int>& nums) {
        vector<string> str_nums;
        for(int i = 0 ; i < nums.size(); i++){
            str_nums.push_back(to_string(nums[i]));
        }
        sort(str_nums.begin(), str_nums.end(), cmp);
        string ans = "";
        for(int i = str_nums.size() - 1; i >= 0 ; i--){
            ans += str_nums[i];
        }
        if (ans.find("0") == 0) return "0";
        return ans;
    }
};