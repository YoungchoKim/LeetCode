class Solution {
public:
    int ltor[2000];
    int rtol[2000];
    vector<int> minOperations(string boxes) {
        vector<int> ans;
        int oneCnt = 0;
        for(int i = 0 ; i < boxes.size() - 1; i++){
            if(boxes[i] == '1'){
                oneCnt++;
            }
            ltor[i+1] = ltor[i] + oneCnt;
        }
        oneCnt = 0;
        for(int i = boxes.size() - 1; i > 0 ; i--){
            if(boxes[i] == '1'){
                oneCnt++;
            }
            rtol[i-1] = rtol[i] + oneCnt;
        }
        for(int i = 0 ; i < boxes.size(); i++){
            ans.push_back(ltor[i] + rtol[i]);
        }
        return ans;
    }
};