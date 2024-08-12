bool maxCmp(int a, int b){
    return a > b;
}
bool minCmp(int a, int b){
    return a < b;
}
struct _heap{
    int arr[40000];
    int size;
    bool (*cmp)(int , int);
    _heap(){
        size = 1;
    }
    void setCmp(bool (*compare)(int, int)){
        cmp = compare;
    }
    void push(int a){
        arr[size++] = a;
        int idx = size - 1;
        while(idx > 1 && cmp(arr[idx], arr[idx/2])){
            int tmp = arr[idx];
            arr[idx] = arr[idx/2];
            arr[idx/2] = tmp;
            idx/=2;
        }
    }
    int pop(){
        int ret = arr[1];
        arr[1] = arr[--size];
        int i = 1;
        while(true){
            int j = i * 2;
            if (j >= size) break;
            if (j + 1 < size && cmp(arr[j+1], arr[j])){
                j++;
            }
            if (cmp(arr[j], arr[i])){
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
                i = j;
            } else {
                break;
            }
        }
        return ret;
    }
    bool empty(){
        return size == 1;
    }
};

class KthLargest {
public:
    _heap minHeap;
    _heap maxHeap;
    int K;
    vector<int> tmp;
    KthLargest(int k, vector<int>& nums) {
        K = k;
        minHeap.setCmp(minCmp);
        maxHeap.setCmp(maxCmp);
        for(int i = 0 ; i < nums.size(); i++){
            maxHeap.push(nums[i]);
        }
        while(k--){
            if (!maxHeap.empty())
                minHeap.push(maxHeap.pop());
        }
    }
    
    int add(int val) {
        if (minHeap.size <= K){
           minHeap.push(val); 
        }
        else if (minHeap.arr[1] < val){
            maxHeap.push(minHeap.pop());
            minHeap.push(val);
        } else {
            maxHeap.push(val);
        }
        
        return minHeap.arr[1];
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */