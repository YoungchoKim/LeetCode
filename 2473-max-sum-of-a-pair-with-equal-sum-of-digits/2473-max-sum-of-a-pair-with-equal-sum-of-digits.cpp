class Solution {
public:
    unordered_map<int, vector<int>> map;
    int digit_sum(int num){
        int s = 0;
        while(num){
            s += num % 10;
            num /= 10;
        }
        return s;
    }
    int maximumSum(vector<int>& nums) {
        for(int i = 0 ; i < nums.size(); i++){
            int digit = digit_sum(nums[i]);
            if(map[digit].size() < 2){
                map[digit].push_back(nums[i]);
                if(map[digit].size() == 2 && map[digit][0] < map[digit][1]){
                    int t = map[digit][0];
                    map[digit][0] = map[digit][1];
                    map[digit][1] = t;
                }
            } else{
                if(map[digit][0] <= nums[i]){
                    map[digit][1] = map[digit][0];
                    map[digit][0] = nums[i];
                } else{
                    map[digit][1] = max(map[digit][1], nums[i]);
                }
            }
        }
        int ans = -1;
        for(auto iter: map){
            if((iter.second).size() == 2){
                if(ans < (iter.second[0] + iter.second[1])){
                    ans = iter.second[0] + iter.second[1];
                }
            }
        }
        return ans;
    }
};