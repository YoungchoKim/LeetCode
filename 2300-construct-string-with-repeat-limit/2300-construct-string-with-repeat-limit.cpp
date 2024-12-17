class Solution {
public:
    vector<char> arr;
    int charCnt[256];
    string repeatLimitedString(string s, int repeatLimit) {
        for(int i = 0 ; i < s.size(); i++){
            charCnt[s[i]]++;
        }
        for(int i = 'z'; i >= 'a'; i--){
            while(charCnt[i]--){
                arr.push_back(i);
            }
        }
        int repeat = 1;
        int beforeChar = arr[0];
        int j = 0;
        for(int i = 1 ; i < arr.size(); i++){
            if(beforeChar == arr[i]){
                repeat++;
            } else {
                repeat = 1;
                beforeChar = arr[i];
            }
            if(repeat > repeatLimit){
                if (j <= i){
                    j = i + 1;
                }
                while(j < arr.size() && beforeChar == arr[j]){
                    j++;
                }
                if(j >= arr.size()){
                    arr[i] = 0;
                    break;
                }
                char t = arr[i];
                arr[i] = arr[j];
                arr[j] = t;
                beforeChar = arr[i];
                repeat = 1;
                j++;
            }
        }
        string ans = "";
        for(int i = 0 ; i < arr.size(); i++){
            if(arr[i] == 0) break;
            ans += arr[i];
        }
        return ans;
    }
};