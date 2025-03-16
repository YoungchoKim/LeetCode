class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long l = 0;
        long long r = 100000000000000;
        long long ans = 0;
        while(l <= r){
            long long mid = (l + r ) / 2;
            long long repairCar = 0;
            for(int i = 0 ; i < ranks.size(); i++){
                long long tmp = mid/ranks[i];
                repairCar += sqrt(tmp);
            }
            if(repairCar < cars){
                l = mid + 1;
            } else{
                ans = mid;
                r = mid - 1;
            }
        }
        return ans;
    }
};