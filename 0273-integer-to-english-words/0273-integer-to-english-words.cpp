class Solution {
public:
    string digitOf1000[5] = {
        "",
        " Thousand",
        " Million",
        " Billion"

    };
    string digitOf10[11] = {
        "",
        " Ten",
        " Twenty",
        " Thirty",
        " Forty",
        " Fifty",
        " Sixty",
        " Seventy",
        " Eighty",
        " Ninety"
    };
    string underTwenty[21] = {
        "",
        " One",
        " Two",
        " Three",
        " Four",
        " Five",
        " Six",
        " Seven",
        " Eight",
        " Nine",
        " Ten",
        " Eleven",
        " Twelve",
        " Thirteen",
        " Fourteen",
        " Fifteen",
        " Sixteen",
        " Seventeen",
        " Eighteen",
        " Nineteen"
    };
    string getUnderHndred(int num){
        if (num < 20){
            return underTwenty[num];
        }
        string s = "";
        if (num / 10 > 0){
            s += digitOf10[num/10];
        }
        if (num %10 > 0){
            s += underTwenty[num % 10];
        }
        return s;
    }

    string numberToWords(int num) {
        string res = "";
        int cnt = 0;
        if (num == 0) return "Zero";
        while(num){
            string s = "";
            int num2 = (num % 1000);
            if ( num2 / 100){
                s += underTwenty[num2/100] + " Hundred";
            }
            s += getUnderHndred(num2 % 100);
            if (s.compare("") != 0)
                res = s + digitOf1000[cnt] + res;
            num /= 1000;
            cnt++;
        }
        return res.substr(1);
    }
};