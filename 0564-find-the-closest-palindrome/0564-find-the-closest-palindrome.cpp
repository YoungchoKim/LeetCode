class Solution {
public:
    long long strToInt(string n){
        long long pow = 1;
        long long res = 0;
        for(int i =  n.size() -1 ; i >= 0; i--){
            res += pow * (n[i] - '0');
            pow *=10;
        }
        return res;
    }
    string nearestPalindromic(string n) {
        long long N = strToInt(n);
        int len = n.size();
        if (len == 1){
            return to_string(N -1);
        } else if (n.compare("10") == 0 || n.compare("11") == 0){
            return "9";
        }
        int mid = (len + 1) / 2;
        string preNum = n.substr(0,mid);
        string postNum = n.substr(mid);
        string preCmpNum = string(preNum);
        if (len %2){
            preCmpNum = preCmpNum.substr(0, mid-1);
        }
        reverse(preCmpNum.begin(), preCmpNum.end());

        long long pre1 = strToInt(preNum) - 1;
        long long pre2 = strToInt(preNum);
        long long pre3 = strToInt(preNum) + 1;


        string preStr1 = to_string(pre1);
        string preStr2 = to_string(pre2);
        string preStr3 = to_string(pre3);
        string postStr1, postStr2, postStr3;
        bool offset1 = false, offset2 = false, offset3 = false;
        if (len%2){
            offset1 = !offset1;
            offset2 = !offset2;
            offset3 = !offset3;
        }
        if (preStr1.size() != preStr2.size()){
            offset1 = !offset1;
            if(len %2 == 0){
                preStr1 += "9";
            }
            
        }
        if (preStr2.size() != preStr3.size()){
            offset3 = !offset3;
            if (len %2)
                preStr3 = preStr3.substr(0, preStr3.size()-1);
        }
        postStr1 = preStr1.substr(0, preStr1.size() - offset1);
        postStr2 = preStr2.substr(0, preStr2.size() - offset2);
        postStr3 = preStr3.substr(0, preStr3.size() - offset3);
        reverse(postStr1.begin(), postStr1.end());
        reverse(postStr2.begin(), postStr2.end());
        reverse(postStr3.begin(), postStr3.end());

        string number[3];
        long long diff[3];
        number[0] = preStr1 + postStr1;
        number[1] = preStr2 + postStr2;
        number[2] = preStr3 + postStr3;
        diff[0] = abs(strToInt(number[0]) - N);
        diff[1] = abs(strToInt(number[1]) - N);
        diff[2] = abs(strToInt(number[2]) - N);
        
        if (diff[1] == 0) return diff[0] <= diff[2] ? number[0] : number[2];
        
        int minIdx = 0;
        long long minDiff = diff[0];
        for(int i = 1; i < 3; i++){
            if (minDiff > diff[i]){
                minDiff = diff[i];
                minIdx = i;
            }
        }
        
        return number[minIdx];
    }
};