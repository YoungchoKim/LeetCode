class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        if(weights.size() == k) return 0;
        vector<long long> prefixSum;
        long long sum = weights[0];
        for(int i = 1 ; i < weights.size(); i++){
            sum += weights[i];
            prefixSum.push_back(sum);
            sum -= weights[i-1];
        }
        sort(prefixSum.begin(), prefixSum.end());

        long long maxScore = weights[0] + weights[weights.size() - 1];
        long long minScore = weights[0] + weights[weights.size() - 1];
        for(int i = 0; i < k - 1; i++){
            minScore += prefixSum[i];
            maxScore += prefixSum[prefixSum.size() - 1 - i];
        }

        return maxScore - minScore;
    }
};