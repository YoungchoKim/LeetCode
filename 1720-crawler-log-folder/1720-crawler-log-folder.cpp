class Solution {
public:
    int minOperations(vector<string>& logs) {
        int cnt = 0;
        for(int i = 0; i < logs.size(); i++){
            if(!logs[i].compare("../")){
                cnt = cnt - 1 < 0 ? 0 : cnt - 1;
            } else if (!logs[i].compare("./")){

            } else {
                cnt++;
            }
        }
        return cnt;
    }
};