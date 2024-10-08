struct _stack{
    char arr[1000001];
    int top;
    _stack(){
        top = 0;
    }
    void push(char a){
        arr[top++] = a;
    }
    bool empty(){
        return top == 0;
    }
    char peek(){
        if(empty()) return -1;
        return arr[top-1];
    }
    void pop(){
        if(empty()) return;
        top--;
    }
};

class Solution {
public:
    _stack st;
    int minSwaps(string s) {
        int res = 0;
        for(int i = 0 ; i < s.size(); i++){
            if(st.empty()){
                st.push(s[i]);
                continue;
            }
            char a = st.peek();
            char b = s[i];
            if(a == '[' && b == ']'){
                st.pop();
                continue;
            } else{
                st.push(b);
            }
        }
        return (st.top/2+1)/2;
    }
};