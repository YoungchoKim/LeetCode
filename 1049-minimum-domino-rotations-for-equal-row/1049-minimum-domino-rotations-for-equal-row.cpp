class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int cur = tops[0];
        bool success = true;
        for(int i = 0 ; i < tops.size(); i++){
            if(tops[i] == cur || bottoms[i] == cur) continue;
            success = false;
            break;
        }
        if(!success){
            success = true;
            cur = bottoms[0];
            for(int i = 0 ; i < tops.size(); i++){
                if(tops[i] == cur || bottoms[i] == cur) continue;
                success = false;
                break;
            }
        }
        if(!success) return -1;

        int cnt1 = 0;
        int cnt2 = 0;
        for(int i = 0 ; i < tops.size(); i++){
            if(tops[i] != cur) cnt1++;
            if(bottoms[i] != cur) cnt2++;
        }
        return cnt1 < cnt2 ? cnt1 : cnt2;
    }
};