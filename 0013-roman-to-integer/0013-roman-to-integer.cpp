class Solution {
public:
    int romanToInt(string s) {
        unordered_map<string, int> dict;
        dict["M"] = 1000;
        dict["D"] = 500;
        dict["C"] = 100;
        dict["L"] = 50;
        dict["X"] = 10;
        dict["V"] = 5;
        dict["I"] = 1;
        dict["CM"] = 900;
        dict["CD"] = 400;
        dict["XC"] = 90;
        dict["XL"] = 40;
        dict["IX"] = 9;
        dict["IV"] = 4;
        int res = 0;
        for(int i = 0 ; i < s.size(); i++){
            string twoLetter = s.substr(i,2);
            if(dict.find(twoLetter) != dict.end()){
                res += dict[twoLetter];
                i++;
            } else{
                res += dict[string(1, s[i])];
            }
        }
        return res;
    }
};