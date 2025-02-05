class Solution {
public:
    vector<int> diffIdx;
    bool areAlmostEqual(string s1, string s2) {
        for(int i = 0 ; i < s1.size(); i++){
            if(s1[i] != s2[i]){
                diffIdx.push_back(i);
            }
        }
        if(diffIdx.size() == 0) return true;
        if(diffIdx.size() != 2) return false;
        if(s1[diffIdx[0]] != s2[diffIdx[1]]){
            return false;
        }
        if(s1[diffIdx[1]] != s2[diffIdx[0]]){
            return false;
        }
        return true;
    }
};