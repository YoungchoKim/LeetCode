class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int N = nums.size();
        int l = 0;
        int r = 1000000;
        int ans = 0;
        while(l <= r ){
            int mid = (l + r) / 2;
            int left = 0;
            int right = 0;
            int cnt = 0;
            int beforeRight = 0;
            while(right < N){
                while(right < N && nums[right] - nums[left] <= mid){
                    right++;
                }
                int NN = right - left;
                cnt += (NN * (NN-1))/2;
                if (left != 0){
                    NN = (beforeRight - left);
                    cnt -= (NN * (NN-1))/2;
                }
                beforeRight = right;
                while(left < right && nums[right] - nums[left] > mid){
                    left++;
                }
            }
            if (cnt >= k){
                if (cnt == k){
                    ans = mid;
                }
                ans = mid;
                r = mid - 1;
            } else{
                l = mid + 1;
            }
        }
        return ans;
    }
};