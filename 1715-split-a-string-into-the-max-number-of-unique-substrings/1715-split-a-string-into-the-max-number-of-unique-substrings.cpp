#define BUCKET_SIZE 1024
struct _vector{
    string *arr;
    int size;
    int capacity;
    _vector(){
        capacity = 2;
        arr = new string[capacity];
        size = 0;
    }
    void push(string a){
        if (size == capacity){
            capacity *= 2;
            string* tmp = new string[capacity];
            for(int i = 0 ; i < size; i++){
                tmp[i] = arr[i];
            }
            delete[] arr;
            arr = tmp;
        }
        arr[size++] = a;
    }
    string operator[](int index){
        return arr[index];
    }
    void del(string s){
        int i;
        for(i = 0 ; i < size; i++){
            if(s.compare(arr[i]) == 0){
                arr[i] = arr[--size];
                break;
            }
        }
    }
};


struct _hashMap{
    _vector v[BUCKET_SIZE];
    int getHash(string& s){
        unsigned int hash = 31;
        for(int i = 0 ; i < s.size(); i++){
            hash *= s[i]-'a';
            hash %= BUCKET_SIZE;
        }
        return hash;
    }
    bool getString(string s){
        int bucket = getHash(s);
        int size = v[bucket].size;
        for(int i = 0 ; i < size; i++){
            if (v[bucket][i].compare(s) == 0){
                return true;
            }
        }
        return false;
    }
    void push(string s){
        int bucket = getHash(s);
        v[bucket].push(s);
    }
    void pop(string s){
        int bucket = getHash(s);
        v[bucket].del(s);
    }
};

class Solution {
public:
    _vector v;
    _hashMap hm;
    int ans = 0;
    void go(string s, int depth){
        ans = max(ans, depth);
        for(int i = 1 ; i <=s.size(); i++){
            string ss = s.substr(0, i);
            if(hm.getString(ss)){
                continue;
            }
            hm.push(ss);
            go(s.substr(i), depth + 1);
            hm.pop(ss);
        }
    }

    int maxUniqueSplit(string s) {
        go(s, 0);
        
        return ans;
    }
};