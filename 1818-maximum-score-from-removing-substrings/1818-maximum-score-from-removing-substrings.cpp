class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int res = 0;
        vector<char> firstStep;
        string cmpStr;
        int maxScore = max(x, y);
        int minScore = min(x, y);
        if (x > y){
            cmpStr = "ab";
        } else {
            cmpStr = "ba";
        }

        for(int i = 0 ; i < s.size(); i++){
            if (firstStep.size() == 0 || s[i] != cmpStr[1]){
                firstStep.push_back(s[i]);
            } else {
                char c = firstStep.back();
                if (c == cmpStr[0]){
                    res += maxScore;
                    firstStep.pop_back();
                } else {
                    firstStep.push_back(s[i]);
                }
            }
        }
        vector<char> secondStep;

        for(int i = 0 ; i < firstStep.size(); i++){
            if (secondStep.size() == 0 || firstStep[i] != cmpStr[0]){
                secondStep.push_back(firstStep[i]);
            } else {
                char c = secondStep.back();
                if (c == cmpStr[1]){
                    res += minScore;
                    secondStep.pop_back();
                }else {
                    secondStep.push_back(firstStep[i]);
                }
            }
        }
        return res;
    }
};