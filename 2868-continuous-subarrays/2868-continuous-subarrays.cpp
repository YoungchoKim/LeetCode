class Solution {
public:
    struct _heap{
        function<bool(int, int)> cmp;
        int arr[100002];
        int size;
        _heap(){
            size = 1;
        }
        void push(int a){
            arr[size++] = a;
            int idx = size - 1;
            while(idx > 1 && !cmp(arr[idx/2], arr[idx])){
                int t = arr[idx/2];
                arr[idx/2] = arr[idx];
                arr[idx] = t;
                idx/=2;
            }
        }
        int pop(){
            int ret = arr[1];
            arr[1] = arr[--size];
            int i = 1;
            while(true){
                int j = i * 2;
                if(j >= size) break;
                if(j+1 < size && !cmp(arr[j], arr[j+1])){
                    j++;
                }
                if(!cmp(arr[i], arr[j])){
                    int t = arr[i];
                    arr[i] = arr[j];
                    arr[j] = t;
                    i = j;
                } else{
                    break;
                }
            }
            return ret;
        }
        int top(){
            return arr[1];
        }
        bool empty(){
            return size == 1;
        }
    };
    long long continuousSubarrays(vector<int>& nums) {
        long long sum = 0;
        long long l = 0;
        long long r = 0;
        _heap minHeap;
        _heap maxHeap;
        minHeap.cmp = [&nums](int a, int b) { return nums[a] < nums[b] ;};
        maxHeap.cmp = [&nums](int a, int b) { return nums[a] > nums[b] ;};
        while(r < nums.size()){
            minHeap.push(r);
            maxHeap.push(r);
            
            while(l < r && nums[maxHeap.top()] - nums[minHeap.top()] > 2){
                l++;
                while(!minHeap.empty() && minHeap.top() < l){
                    minHeap.pop();
                }
                while(!maxHeap.empty() && maxHeap.top() < l){
                    maxHeap.pop();
                }
            }
            sum += r - l + 1;
            r++;
        }
        return sum;
    }
};