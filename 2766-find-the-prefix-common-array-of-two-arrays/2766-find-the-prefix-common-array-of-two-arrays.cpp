class Solution {
public:
    int bitCount(unsigned long long num){
        int cnt = 0;
        while(num){
            cnt++;
            num &= num-1;
        }
        return cnt;
    }
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unsigned long long subsetA = 0;
        unsigned long long subsetB = 0;
        vector<int> ans;
        for(int i = 0 ; i < A.size(); i++){
            subsetA |= 1ULL << A[i];
            subsetB |= 1ULL << B[i];
            ans.push_back(bitCount(subsetA & subsetB));
        }
        return  ans;
    }
};