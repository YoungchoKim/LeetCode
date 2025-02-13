struct _heap{
    long long arr[400002];
    int size;
    _heap(){
        size = 1;
    }
    void push(long long a){
        arr[size++] = a;
        int idx = size - 1;
        while(idx > 1 && arr[idx/2] > arr[idx]){
            long long t = arr[idx];
            arr[idx] = arr[idx/2];
            arr[idx/2] = t;
            idx /= 2;
        }
    }
    long long pop(){
        long long ret = arr[1];
        arr[1] = arr[--size];
        int i = 1;
        while(true){
            int j = i * 2;
            if (j >= size) break;
            if(j + 1 < size && arr[j] > arr[j + 1]){
                j++;
            }
            if(arr[i] > arr[j]){
                long long t = arr[i];
                arr[i] = arr[j];
                arr[j] = t;
                i = j;
            }else{
                break;
            }
        }
        return ret;
    }
    bool empty(){
        return size == 1;
    }
};

class Solution {
public:
    _heap pq;
    int minOperations(vector<int>& nums, int k) {
        for(int i = 0 ; i < nums.size(); i++){
            pq.push(nums[i]);
        }
        int cnt = 0;
        while(!pq.empty()){
            long long x = pq.pop();
            if (x >= k) break;
            long long y = pq.pop();
            cout << x << " " << y << endl;
            pq.push(min(x, y)*2 + max(x, y));
            cnt++;
        }
        return cnt;
    }
};