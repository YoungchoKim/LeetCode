struct _node{
    int pass;
    int total;
};
struct _heap{
    _node arr[100002];
    int size;
    function<bool(_node, _node)> cmp;
    _heap(){
        size = 1;
    }
    void push(_node a){
        arr[size++] = a;
        int idx = size - 1;
        while(idx > 1 && cmp(arr[idx/2], arr[idx])){
            _node t = arr[idx];
            arr[idx] = arr[idx/2];
            arr[idx/2] = t;
            idx /= 2;
        }
    }
    _node pop(){
        _node ret = arr[1];
        arr[1] = arr[--size];
        int i = 1;
        while(true){
            int j = i * 2;
            if(j >= size) break;
            if(j+1 < size && cmp(arr[j], arr[j+1])){
                j++;
            }
            if(cmp(arr[i], arr[j])){
                _node t = arr[i];
                arr[i] = arr[j];
                arr[j] = t;
                i = j;
            } else{
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
    _heap h;
    double getRatio(_node classs){
        double pass = classs.pass;
        double total = classs.total;
        return pass / total;
    }
    double diffRatio(_node a){
        double ratio1 = getRatio(a);
        double ratio2 = getRatio({a.pass+1, a.total+1});
        return ratio2 - ratio1;
    }
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        h.cmp = [&](_node a, _node b) {
            double diffRatio1 = diffRatio(a);
            double diffRatio2 = diffRatio(b);
            return diffRatio1 < diffRatio2;
        };
        for(int i = 0 ; i < classes.size(); i++){
            h.push({classes[i][0], classes[i][1]});
        }
        while(extraStudents--){
            _node clas = h.pop();
            h.push({clas.pass+1, clas.total+1});
        }
        double sum = 0;
        while(!h.empty()){
            sum += getRatio(h.pop());
        }
        return sum / classes.size();
    }
};