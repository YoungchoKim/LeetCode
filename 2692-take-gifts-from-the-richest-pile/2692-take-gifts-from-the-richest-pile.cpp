struct _heap{
    int arr[1002];
    int size;
    _heap(){
        size = 1;
    }
    void push(int a){
        arr[size++] = a;
        int idx = size - 1;
        while(idx > 1 && arr[idx] > arr[idx/2]){
            int t = arr[idx];
            arr[idx] = arr[idx/2];
            arr[idx/2] = t;
            idx/=2;
        }
    }
    int pop(){
        int ret = arr[1];
        arr[1] = arr[--size];
        int i = 1;
        while(true){
            int j = i * 2;
            if(j>= size) break;
            if(j+1 < size && arr[j] < arr[j+1]){
                j++;
            }
            if(arr[i] < arr[j]){
                int t = arr[i];
                arr[i] = arr[j];
                arr[j] = t;
                i = j;
            } else {
                break;
            }
        }


        return ret;
    }
};

class Solution {
public:
    _heap h;
    long long pickGifts(vector<int>& gifts, int k) {
        for(int i = 0 ; i < gifts.size(); i++){
            h.push(gifts[i]);
        }
        while(k--){
            int gift = h.pop();
            int i = 1;
            while(i*i <= gift) i++;
            i--;
            h.push(i);
        }
        long long sum = 0;
        for(int i = 1; i < h.size; i++){
            sum += h.arr[i];
        }
        return sum;
    }
};