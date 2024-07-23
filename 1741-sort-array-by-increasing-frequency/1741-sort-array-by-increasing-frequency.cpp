class Solution {
    int cnt[300] = {0};
    int tmp[100];
    void merge(vector<int>& nums, int l, int mid, int r){
        int i = l;
        int j = mid + 1;
        int cur = i;
        while( i <= mid && j <= r){
            if (cnt[nums[i] + 100] < cnt[nums[j] + 100]){
                tmp[cur++] = nums[i++];
            } 
            else if(cnt[nums[i] + 100] == cnt[nums[j] + 100] && nums[i] > nums[j]){
                tmp[cur++] = nums[i++];
            }
            else{
                tmp[cur++] = nums[j++];
            }
        }
        while(i <= mid){
            tmp[cur++] = nums[i++];
        }
        for(i = l; i < cur; i++){
            nums[i] = tmp[i];
        }
    }
    void merge_sort(vector<int> &nums, int l, int r){
        if (l >= r) return;
        int mid = (l + r) / 2;
        merge_sort(nums, l, mid);
        merge_sort(nums, mid+1, r);
        merge(nums, l, mid, r);
    }    
public:
    vector<int> frequencySort(vector<int>& nums) {
        for(int i = 0 ; i < nums.size(); i++){
            cnt[nums[i] + 100]++;
        }
        merge_sort(nums, 0, nums.size() -1);
        return nums;
    }
};