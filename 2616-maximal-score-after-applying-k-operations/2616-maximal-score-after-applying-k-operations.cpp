struct _heap{
    int arr[100001];
    int size;
    _heap(){
        size = 1;
    }
    void push(int a){
        arr[size++] = a;
        int idx = size - 1;
        while(idx > 1 && arr[idx] > arr[idx/2]){
            int t= arr[idx];
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
            int j = i*2;
            if(j >= size){
                break;
            }
            if (j+1 < size && arr[j+1] > arr[j]){
                j++;
            }
            if(arr[j] > arr[i]){
                int t = arr[j];
                arr[j] = arr[i];
                arr[i] = t;
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
    long long maxKelements(vector<int>& nums, int k) {
        long long score = 0;
        for(int i = 0 ; i < nums.size(); i++){
            h.push(nums[i]);
        }
        while(k--){
            int n = h.pop();
            score += n;
            int t1 = n/3;
            double t2 = (double)n/3;
            h.push(t1 == t2 ? t1 : (int)(t2 + 1));
        }
        return score;
    }
};