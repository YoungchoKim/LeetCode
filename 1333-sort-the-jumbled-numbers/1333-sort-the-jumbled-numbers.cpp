class Solution {
public:
    int tmp[30001];
    int getNum(vector<int>& mapping, int a){
        int pow = 1;
        int res = 0;
        if (a == 0) return mapping[a];
        while(a){
            res += (mapping[a%10])*pow;
            pow *= 10;
            a /= 10;
        }
        return res;
    }
    void merge(vector<int>& mapping, vector<int>& nums, int l, int mid, int r ){
        int i = l;
        int j = mid + 1;
        int cur = i;
        while(i <= mid && j <= r){
            if(getNum(mapping, nums[i]) <= getNum(mapping, nums[j])){
                tmp[cur++] = nums[i++];
            } else {
                tmp[cur++] = nums[j++];
            }
        }
        while(i <= mid){
            tmp[cur++] = nums[i++];    
        }
        for(i = l ; i < cur; i++){
            nums[i] = tmp[i];
        }
    }
    void merge_sort(vector<int>& mapping, vector<int>& nums, int l, int r ){
        if (l >= r) return;
        int mid = (l + r) / 2;
        merge_sort(mapping, nums, l, mid);
        merge_sort(mapping, nums, mid+1, r);
        merge(mapping, nums, l, mid, r);
    }
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        merge_sort(mapping, nums, 0, nums.size() - 1);
        return nums;
    }
};