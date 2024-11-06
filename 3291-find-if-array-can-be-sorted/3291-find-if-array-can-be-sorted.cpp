struct _heap{
    int arr[102];
    int size;
    _heap(){
        size = 1;
    }
    void push(int a){
        arr[size++] = a;
        int idx = size - 1;
        while(idx > 1 && arr[idx/2] > arr[idx]){
            int t = arr[idx/2];
            arr[idx/2] = arr[idx];
            arr[idx] = t;
            idx /= 2;
        }
    }
    int pop(){
        int ret = arr[1];
        arr[1] = arr[--size];
        int i = 1;
        while(true){
            int j = i * 2;
            if(j >= size) break;
            if(j+1 < size && arr[j+1] < arr[j]){
                j++;
            }
            if(arr[i] > arr[j]){
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
    _heap h[10];
    int getOneCnt(int num){
        int cnt = 0;
        while(num){
            cnt++;
            num &= num-1;
        }
        return cnt;
    }
    vector<int> arr;
    bool canSortArray(vector<int>& nums) {
        int beforeCnt = getOneCnt(nums[0]);
        int beforeMax = 0;
        int maxNum = nums[0];
        for(int i = 1 ; i < nums.size(); i++){
            int cnt = getOneCnt(nums[i]);
            if( cnt != beforeCnt){
                if(maxNum > nums[i]) return false;
                beforeMax = maxNum;
                maxNum = nums[i];
                beforeCnt = cnt;
                continue;
            }
            if(beforeMax > nums[i]) return false;
            if(maxNum < nums[i]){
                maxNum = nums[i];
            }
        }

        return true;
    }
};