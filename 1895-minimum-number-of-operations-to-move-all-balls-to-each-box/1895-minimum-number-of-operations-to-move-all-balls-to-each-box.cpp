class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> ans;
        for(int i = 0 ; i < boxes.size(); i++){
            int operation = 0;
            for(int j = 0 ; j < boxes.size(); j++){
                if(i == j || boxes[j] == '0') continue;
                operation += abs(i - j);
            }
            ans.push_back(operation);
        }    
        return ans;
    }
};