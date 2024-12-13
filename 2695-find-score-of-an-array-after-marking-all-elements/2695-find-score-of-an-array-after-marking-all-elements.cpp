struct _node{
    int idx;
    int val;
};

bool _cmp(_node a, _node b){
    if(a.val != b.val) return a.val < b.val;
    return a.idx < b.idx;
}

struct _heap{
    _node arr[100002];
    int size;
    _heap(){
        size = 1;
    }
    void push(_node a){
        arr[size++] = a;
        int idx = size - 1;
        while(idx > 1 && _cmp(arr[idx], arr[idx/2])){
            _node tmp = arr[idx/2];
            arr[idx/2] = arr[idx];
            arr[idx] = tmp;
            idx >>= 1;
        }
    }
    _node pop(){
        _node ret = arr[1];
        arr[1] = arr[--size];
        int i = 1;
        while(true){
            int j = i*2;
            if(j >= size){
                break;
            }
            if(j+1 < size && _cmp(arr[j+1], arr[j])){
                j++;
            }
            if(_cmp(arr[j], arr[i])){
                _node t = arr[i];
                arr[i] = arr[j];
                arr[j] = t;
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
    _node peek(){
        return arr[1];
    }
};

class Solution {
public:
    _heap h;
    _heap remove;
    bool removed[100002];
    long long findScore(vector<int>& nums) {
        for(int i = 0 ; i < nums.size(); i++){
            h.push({i, nums[i]});
        }
        long long sum = 0;
        while(!h.empty()){
            while(!h.empty() && h.peek().val == remove.peek().val && 
                                h.peek().idx == remove.peek().idx){
                remove.pop();
                h.pop();
            }
            if(h.empty()) break;
            _node nod = h.pop();
            cout << nod.val << endl;
            sum += nod.val;
            if(nod.idx -1 >= 0 && !removed[nod.idx-1]){
                removed[nod.idx-1] = true;
                remove.push({nod.idx-1, nums[nod.idx-1]});
            }
            if(nod.idx+1 < nums.size()  && !removed[nod.idx+1]){
                removed[nod.idx+1] = true;
                remove.push({nod.idx+1, nums[nod.idx+1]});
            }
        }
        return sum;
    }
};