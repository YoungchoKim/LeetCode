struct _pair{
    int start;
    int end;
    int chair;
};

struct _heap{
    int size;
    int arr[10001];
    _heap(){
        size = 1;
    }
    void push(int a){
        arr[size++] = a;
        int idx = size - 1;
        while(idx > 0 && arr[idx] < arr[idx/2]){
            int tmp = arr[idx];
            arr[idx] = arr[idx/2];
            arr[idx/2] = tmp;
            idx /= 2;
        }
    }
    int pop(){
        int ret = arr[1];
        int i = 1;
        arr[i] = arr[--size];
        while(true){
            int j = i*2;
            if(j >= size) break;
            if(j+1 < size && arr[j] > arr[j+1]){
                j++;
            }
            if(arr[i] > arr[j]){
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
vector<_pair> _times;

class Solution {
public:
    static bool _cmpStart(int a, int b){
        return _times[a].start > _times[b].start;
    }
    static bool _cmpEnd(int a, int b){
        return _times[a].end > _times[b].end;
    }
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        _times.clear();
        _heap h;
        vector<int> start;
        vector<int> end;
        for(int i = 0 ; i < times.size(); i++){
            _times.push_back({times[i][0], times[i][1], -1});
            start.push_back(i);
            end.push_back(i);
            h.push(i);
        }
        sort(start.begin(), start.end(), _cmpStart);
        sort(end.begin(), end.end(), _cmpEnd);

        int startSize = start.size();
        int endSize = end.size();
        for(int i = 0 ; i <= 100000; i++){
            while(endSize > 0 && _times[end[endSize - 1]].end == i){
                h.push(_times[end[endSize - 1]].chair);
                endSize--;
            }
            while(startSize > 0 && _times[start[startSize - 1]].start == i){
                int chair = h.pop();
                if (start[startSize - 1] == targetFriend){
                    return chair;
                }
                _times[start[startSize - 1]].chair = chair;
                startSize--;
            }
        }
        return 0;
    }
};