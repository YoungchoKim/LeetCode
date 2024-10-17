struct number{
    int n;
    int pow;
};
struct _stack{
    number arr[20];
    int top;
    _stack(){
        top = 0;
    }
    void push(number a){
        arr[top++] = a;
    }
    number pop(){
        return arr[--top];
    }
    number peek(){
        return arr[top - 1];
    }
    bool empty(){
        return top == 0;
    }
};


class Solution {
public:
    _stack st;
    int maximumSwap(int num) {
        vector<number> mostRight;
        int tmpNum = num;
        int pow = 1;
        while(tmpNum){
            int n = tmpNum % 10;
            while (!st.empty() && st.peek().n < n){
                st.pop();
            }
            if(st.empty()){
                st.push({n, pow});
                mostRight.push_back({n, pow});
            } else{
                mostRight.push_back({st.peek().n, st.peek().pow});
            }
            pow *= 10;
            tmpNum /= 10;
        }
        int idx = mostRight.size() - 1;
        while(pow/10){
            pow /= 10;
            int n = (num % (pow*10)) / pow;
            if (mostRight[idx].n != n){
                num -= n * pow;
                num -= mostRight[idx].n * mostRight[idx].pow;
                num += n * mostRight[idx].pow;
                num += mostRight[idx].n * pow;
                return num;
            }

            idx--;
        }
        return num;
    }
};