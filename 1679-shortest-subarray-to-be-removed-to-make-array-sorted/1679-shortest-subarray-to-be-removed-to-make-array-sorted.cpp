class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int left;
        for(left = 0 ; left < arr.size() - 1; left++){
            if(arr[left] > arr[left+1]){
                break;
            }
        }
        if (left == arr.size() - 1) return 0;
        
        int right;
        for(right = arr.size() - 1; right > 0; right--){
            if(arr[right-1] > arr[right]){
                break;
            }
        }
        if (arr[left] <= arr[right]) return right - left -1;
        int t = arr.size() - left -1;
        int ans = min(t, right);
        int i = 0;
        while (i <= left && right < arr.size()){
            if (arr[i] <= arr[right]){
                ans = min(ans, right - i - 1);
            }

            if (i+1 <= left && arr[i+1] <= arr[right]){
                i++;
            } else{
                right++;
            }
        }
        return ans;
    }
};