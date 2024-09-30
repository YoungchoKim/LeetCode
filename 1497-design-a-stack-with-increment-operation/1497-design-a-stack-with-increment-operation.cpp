class CustomStack {
public:
    int stackSize;
    int arr[1001];
    int lazy[1001];
    int top;
    CustomStack(int maxSize) {
        stackSize = maxSize;
        top = 0;
        for(int i = 0 ; i < maxSize; i++){
            lazy[i] = 0;
        }
    }
    
    void push(int x) {
        if (top == stackSize) return;
        arr[top++] = x;
    }
    
    int pop() {
        if (top == 0) return -1;
        top--;
        if (top > 0) lazy[top-1] += lazy[top];
        arr[top] += lazy[top];
        lazy[top] = 0;
        return arr[top];
    }
    
    void increment(int k, int val) {
        if (top == 0) return;
        lazy[min(k-1, top-1)] += val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */