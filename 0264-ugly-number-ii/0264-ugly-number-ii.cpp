struct _heap{
    long long arr[10000];
    int size;
    _heap(){
        size = 1;
    }
    void push(long long a){
        arr[size++] = a;
        int idx = size - 1;
        while(idx > 1 && arr[idx] < arr[idx/2]){
            long long t = arr[idx];
            arr[idx] = arr[idx/2];
            arr[idx/2] = t;
            idx/=2;
        }
    }
    long long pop(){
        long long ret = arr[1];
        arr[1] = arr[--size];
        int i = 1;
        while(true){
            int j = i * 2;
            if (j >= size) break;
            if (j + 1 < size && arr[j] > arr[j+1]){
                j++;
            }
            if(arr[j] < arr[i]){
                long long t = arr[j];
                arr[j] = arr[i];
                arr[i] = t;
                i = j;
            }
            else {
                break;
            }
        }
        return ret;
    }
};

class Solution {
public:
    _heap pq;
    map<long long, bool> processed;
    int nthUglyNumber(int n) {
        if (n == 1) return 1;
        int idx = 1;
        pq.push(1); 
        long long num = 1;      
        while(n--){
            num = pq.pop();
            if (processed[num]) {
                n++;
                continue;
            }
            processed[num] = true;
            cout << num << endl;
            pq.push(num*2);
            pq.push(num*3);
            pq.push(num*5);
        }
        return num;
    }
};