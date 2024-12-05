class Solution {
public:
    int nextCharIdx(string& str, int idx){
        for(int i = idx; i < str.size(); i++){
            if(str[i] == 'L' || str[i] == 'R') return i;
        }
        return str.size();
    }
    bool canChange(string start, string target) {
        int idx1, idx2;
        idx1 = idx2 = 0;
        while(true){
            idx1 = nextCharIdx(start, idx1);
            idx2 = nextCharIdx(target, idx2);
            if(idx1 == start.size() || idx2 == target.size()){       
                break;
            }
            if(start[idx1] != target[idx2]) return false;
            if(start[idx1] == 'L'){
                if(idx1 < idx2){
                    return false;
                }
            }
            if(start[idx1] == 'R'){
                if(idx1 > idx2){
                    return false;
                }
            }
            idx1++;
            idx2++;
        }
        if(idx1 == start.size() && idx2 == target.size()){
            return true;
        }
        return false;
    }
};