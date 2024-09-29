struct _node{
    int cnt;
    int idx;
};
template <typename T1>
struct trie{
    T1 *nod;
    trie<T1>* next[26];
    trie(){
        nod = nullptr;
        for(int i = 0 ; i < 26; i++){
            next[i] = nullptr;
        }
    }
    ~trie(){
        if (nod != nullptr) delete nod;
        for(int i = 0 ; i < 26; i++){
            if(next[i] != nullptr) delete next[i];
            next[i] = nullptr;
        }
    }
};

trie<_node> *root;
_node* getNode(string &s){
    trie<_node>* ptr = root;
    for(char c : s){
        int idx = c - 'a';
        if(ptr->next[idx] == nullptr){
            ptr->next[idx] = new trie<_node>();
        }
        ptr = ptr->next[idx];
    }
    if(ptr->nod == nullptr){
        ptr->nod = new _node();
        ptr->nod->cnt = 0;
        ptr->nod->idx = -1;
    }
    return ptr->nod;
}

template <typename T>
struct _vector{
    T* arr;
    int size;
    int capacity;

    _vector(){
        size = 0;
        capacity = 1;
        arr = new T[capacity];
    }

    void push(T &a){
        if(size == capacity){
            capacity*=2;
            T* tmp = new T[capacity];
            for(int i = 0 ; i < size; i++){
                tmp[i] = arr[i];
            }
            delete[] arr;
            arr = tmp;
        }
        arr[size++] = a;
    }

    void del(int idx){
        arr[idx] = arr[--size];
        _node* nod = getNode(arr[idx]);
        nod->idx = idx;
    }
    T operator[](int idx){
        return arr[idx];
    }
};


class AllOne {
private:
    _vector<string> v[50001];
public:
    int maxKey;
    int minKey;
    AllOne() {
        root = new trie<_node>();
        minKey = maxKey = 1;
    }
    ~AllOne() {
        delete root;
    }
    
    void inc(string key) {
        _node* nod = getNode(key);
        if(nod->cnt == minKey && v[nod->cnt].size == 1){
            minKey++;
        }
        if (nod->cnt == 0){
            minKey = 1;
        }
        if (nod->cnt == maxKey){
            maxKey++;
        }
        nod->cnt++;
        if(nod->cnt != 1){
            v[nod->cnt-1].del(nod->idx);
        }
        nod->idx = v[nod->cnt].size;
        v[nod->cnt].push(key);
        
    }
    
    void dec(string key) {
        _node* nod = getNode(key);
        if (nod->cnt == maxKey && v[nod->cnt].size == 1){
            maxKey--;
        }
        if (nod->cnt == minKey){
            minKey--;
        }
        
        v[nod->cnt].del(nod->idx);
        nod->cnt--;
        if(nod->cnt != 0){
            nod->idx = v[nod->cnt].size;
            v[nod->cnt].push(key);
        }
        if(minKey == 0){
            for(int i = minKey+1; i <= maxKey; i++){
                if(v[i].size > 0){
                    minKey = i;
                    break;
                }
            }
        }
    }
    
    string getMaxKey() {
        if (v[maxKey].size > 0) return v[maxKey][0];
        return "";
    }
    
    string getMinKey() {
        if (v[minKey].size > 0) return v[minKey][0];

        return "";
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */