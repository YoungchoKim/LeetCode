class Solution {
public:
    int getSum(int n){
        int s = 0;
        while(n){
            s += n % 10;
            n /= 10;
        }
        return s;
    }
    int countLargestGroup(int n) {
        vector<int> groups[37];
        int largestGroupSize = 0;
        int ans = 0;
        for(int i = 1; i <= n; i++){
            int group = getSum(i);
            groups[group].push_back(i);
            if(largestGroupSize < groups[group].size()){
                largestGroupSize = groups[group].size();
                ans = 1;
            } else if(largestGroupSize == groups[group].size()){
                ans++;
            }
        }
        return ans;
    }
};