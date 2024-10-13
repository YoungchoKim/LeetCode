struct _node{
    int num;
    int idx;
};
bool _asc(_node a, _node b){
    if(a.num != b.num) return a.num < b.num;
    return a.idx < b.idx;
}
bool _dec(_node a, _node b){
    if(a.num != b.num) return a.num > b.num;
    return a.idx < b.idx;
}
struct _heap{
    _node arr[3500*50];
    int size;
    _heap(){
        size = 1;
    }
    bool (*_cmp)(_node a, _node b);
    void setCmp(bool (*func)(_node a, _node b)){
        _cmp = func;
    }
    void push(_node a){
        arr[size++] = a;
        int idx = size - 1;
        while(idx > 1 && _cmp(arr[idx], arr[idx/2])){
            _node t = arr[idx];
            arr[idx] = arr[idx/2];
            arr[idx/2] = t;
            idx/=2;
        }
    }
    _node pop(){
        _node ret = arr[1];
        arr[1] = arr[--size];
        int i = 1;
        while(true){
            int j = i*2;
            if(j >= size) break;
            if(j+1 < size && _cmp(arr[j+1], arr[j])){
                j++;
            }
            if(_cmp(arr[j], arr[i])){
                _node t = arr[j];
                arr[j] = arr[i];
                arr[i] = t;
                i = j;
            } else {
                break;
            }
        }
        return ret;
    }
    int peek(){
        return arr[1].num;
    }
    bool empty(){
        return size == 1;
    }
};

class Solution {
public:
    _heap minHeap;
    _heap maxHeap;
    _heap _maxLazy;
    int numsIdx[3500] = {0};

    void removeMaxHeap(_node a){
        _maxLazy.push(a);
    }
    int peekMaxHeap(){
        while(!_maxLazy.empty() && maxHeap.peek() == _maxLazy.peek()){
            maxHeap.pop();
            _maxLazy.pop();
        }
        return maxHeap.arr[1].num;
    }

    vector<int> smallestRange(vector<vector<int>>& nums) {
        minHeap.setCmp(_asc);
        maxHeap.setCmp(_dec);
        _maxLazy.setCmp(_dec);
        for(int i = 0 ; i < nums.size(); i++){
            minHeap.push({nums[i][0], i});
            maxHeap.push({nums[i][0], i});
        }
        vector<int> res;
        res.push_back(minHeap.peek());
        res.push_back(maxHeap.peek());

        while(true){
            _node n = minHeap.pop();
            removeMaxHeap(n);
            int nextIdx = ++numsIdx[n.idx];
            if(nextIdx >= nums[n.idx].size()) break;
            int nextNum = nums[n.idx][nextIdx];
            minHeap.push({nextNum, n.idx});
            maxHeap.push({nextNum, n.idx});
            if((res[1] - res[0]) > (peekMaxHeap() - minHeap.peek())){
                res[0] = minHeap.peek();
                res[1] = peekMaxHeap();
            }
        }

        return res;
    }
};



