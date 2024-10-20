struct _stack{
    char arr[10001];
    int top;
    _stack(){
        top = 0;
    }
    void push(char a){
        arr[top++] = a;
    }
    char pop(){
        return arr[--top];
    }
    bool empty(){
        return top == 0;
    }
    char peek(){
        return arr[top - 1];
    }
};

class Solution {
public:
    _stack st;
    vector<char> v;
    char strToInt[256];
    bool process(char oper, vector<char>& v){
        if (oper == '!'){
            return !(strToInt[v[0]]);
        }
        if (oper == '|'){
            bool res = strToInt[v[0]];
            for(int i = 1; i < v.size(); i++){
                res |= strToInt[v[i]];
                if(res) return true;
            }
        }
        bool res = strToInt[v[0]];
        for(int i = 1; i < v.size(); i++){
            res &= strToInt[v[i]];
        }
        return res;
    }

    bool parseBoolExpr(string expression) {
        strToInt['f'] = 0;
        strToInt['t'] = 1;
        bool res;
        for(char c: expression){
            if (c != ')'){
                if(c == ',') continue;
                st.push(c);
                continue;
            } 
            while(st.peek() != '('){
                v.push_back(st.pop());
            }
            st.pop();
            char oper = st.pop();
            res = process(oper,v );
            st.push(res ? 't':'f');
            v.clear();
        }
        return st.peek() == 't' ? true: false;
    }
};