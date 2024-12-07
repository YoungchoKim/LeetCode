class Solution {
public:
    
    
    int minimumSize(vector<int>& nums, int maxOperations) {
        int _max = 0;
        for(int i = 0 ; i < nums.size(); i++){
            if (_max < nums[i]){
                _max = nums[i];
            }
        }
        int l = 1; 
        int r = _max;
        int ans = _max;
        while(l <= r){
            int mid = l + (r - l)/2;
            cout << mid << endl;
            int operation = maxOperations;
            bool success = true;
            for(int i = 0 ; i < nums.size(); i++){
                if(mid < nums[i]){
                    operation -= ((nums[i] + mid - 1) / mid) - 1;
                }
                if(operation < 0){
                    success = false;
                    break;
                }
            }
            if(success){
                r = mid -1;
                ans = mid;
            } else{
                l= mid + 1;
            }

        }        

        return ans;
    }
};