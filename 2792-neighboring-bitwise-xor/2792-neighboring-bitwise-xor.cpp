class Solution {
public:
    vector<int> original;
    bool doesValidArrayExist(vector<int>& derived) {
        int N = derived.size();
        derived.push_back(derived[0]);
        original.push_back(derived[0]);
        for(int i = 0 ; i < N; i++){
            original.push_back(derived[i] ^ original[i]);
        }
        return original[0] == original[N];
    }
};