class Solution {
public:
    int lastIdx[256];
    vector<int> partitionLabels(string s) {
        for(int i = 0 ; i < s.size(); i++){
            lastIdx[s[i]] = i;
        }

        vector<int> ans;
        int start = 0;
        int end = 0;
        for(int i = 0 ; i < s.size(); i++){
            end = max(end, lastIdx[s[i]]);
            if(end == i){
                ans.push_back(end - start + 1);
                start = end = end +1;
            }
        }
        return ans;
    }
};