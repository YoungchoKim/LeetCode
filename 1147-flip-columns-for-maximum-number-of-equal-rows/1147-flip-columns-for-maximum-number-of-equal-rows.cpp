template <typename T>
struct _vector{
    T* arr;
    int size;
    int capacity;
    _vector(){
        size = 0;
        capacity = 2;
        arr = new T[capacity];
    }
    void push(T a){
        if(size == capacity){
            capacity *= 2;
            T* tmp = new T[capacity];
            for(int i = 0 ; i < size ; i++){
                tmp[i] = arr[i];
            }
            delete[] arr;
            arr = tmp;
        }
        arr[size++] = a;
    }
    T operator[](int idx){
        return arr[idx];
    }
};

struct _node{
    string s;
    int cnt;
};

struct _node2{
    unsigned int key;
    int idx;
};

#define MAP_SIZE 300
struct _map{
    _vector<_node> arr[MAP_SIZE];
    _vector<_node2> nodeList;
    _map(){
        for(int i = 0 ; i < MAP_SIZE; i++){
            arr[i].size = 0;
        }
        nodeList.size = 0;
    }
    void push(string s){
        unsigned int key = 1;
        for(int i = 0 ; i < s.size(); i++){
            key *= s[i] - 'a';
            key *= 26;
            key %= MAP_SIZE;
        }
        for(int i = 0; i < arr[key].size; i++){
            if(arr[key][i].s.compare(s) == 0){
                arr[key].arr[i].cnt++;
                return;
            }
        }
        arr[key].push({s, 1});
        nodeList.push({key, arr[key].size - 1});
    }
    int size(){
        return nodeList.size;
    }
    _node getItem(_node2 nod){
        return arr[nod.key][nod.idx];
    }
};

class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        _map hmap;
        for(int i = 0 ; i < matrix.size(); i++){
            string s = "";
            int first = matrix[i][0];
            for(int j = 0 ; j < matrix[i].size(); j++){
                if(first == matrix[i][j]){
                    s += "1";
                } else {
                    s += "0";
                }
            }
            hmap.push(s);
        }
        int ans = 0;
        for(int i = 0; i < hmap.size(); i++){
            ans = max(ans, hmap.getItem(hmap.nodeList[i]).cnt);
        }
        return ans;
    }
};