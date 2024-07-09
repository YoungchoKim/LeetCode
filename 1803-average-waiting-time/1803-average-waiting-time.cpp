class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        long long totalWait = 0;
        long long time = 0;
        for(int i = 0 ; i < customers.size(); i++){
            int arrival = customers[i][0];
            int prepareTime = customers[i][1];

            if (arrival > time){
                time = arrival + prepareTime;
                totalWait += prepareTime;
            } else {
                totalWait += time - arrival + prepareTime;
                time += prepareTime;
            }
        }
        return (double)totalWait / customers.size();
    }
};