struct _node{
    int idx;
    int val;
};

template <typename T>
struct _heap{
    int size;
    T arr[101];
    function<bool(int,int)> cmp;
    _heap(){
        size = 1;
    }
    void push(T a){
        arr[size++] = a;
        int idx = size - 1;
        while(idx > 1 && cmp(arr[idx >> 1], arr[idx])){
            T t = arr[idx >> 1];
            arr[idx >> 1] = arr[idx];
            arr[idx] = t;
            idx >>= 1;
        }
    }
    T pop(){
        T ret = arr[1];
        arr[1] = arr[--size];
        int i = 1;
        while(true){
            int j = i * 2;
            if(j >= size) break;
            if(j+1 < size && cmp(arr[j], arr[j+1])){
                j++;
            }
            if(cmp(arr[i], arr[j])){
                T t = arr[i];
                arr[i] = arr[j];
                arr[j] = t;
                i = j;
            } else{
                break;
            }
        }

        return ret;
    }
};

class Solution {
public:
    _heap<int> h;
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        h.cmp = [&nums](int a, int b){
            if(nums[a] != nums[b]){
                return nums[a] > nums[b];
            }
            return a > b;
        };
        for(int i = 0 ; i < nums.size(); i++){
            h.push(i);
        }
        while(k--){
            int idx = h.pop();
            nums[idx] *= multiplier;
            h.push(idx);
        }
        return nums;
    }
};