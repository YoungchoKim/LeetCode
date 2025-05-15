class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int toggle = groups[0] ^ 1;
        vector<string> ans;
        for(int i = 0 ; i < groups.size(); i++){
            if(toggle != groups[i]){
                ans.push_back(words[i]);
                toggle ^= 1;
            }
        }
        return ans;
    }
};