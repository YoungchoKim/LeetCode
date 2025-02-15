class Solution {
public:
    bool check_punishment(int num,vector<int>& nums, int depth, int goal_num){
        if(num == 0){
            if(nums[0] == goal_num) return false;
            int sum = 0;
            for(int i = 0 ; i < nums.size(); i++){
                sum += nums[i];
            }
            if(sum == goal_num){
                return true;
            } else{
                return false;
            }
        }
        int pow = 10;
        for(int i = 1; i <= 6; i++){
            nums.push_back(num % pow);
            if(check_punishment(num/pow, nums, depth+1, goal_num)){
                nums.pop_back();
                return true;
            }
            pow *= 10;
            nums.pop_back();
        }
        return false;
    }
    int punishmentNumber(int n) {
        vector<int> nums;
        int ans = 0;
        for(int i = 1; i <= n; i++){
            int pow = 10;
            for(int j = 1; j <= 6; j++){
                int nn = i * i;
                nums.push_back(nn % pow);
                if(check_punishment(nn/pow, nums, 1, i)){
                    nums.pop_back();
                    ans += nn;
                    break;
                }
                pow *= 10;
                nums.pop_back();
            }
        }
        
        return ans + 1;
    }
};