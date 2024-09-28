class MyCircularDeque {
public:
    int deque[1001];
    int size;
    int front;
    int rear;
    
    MyCircularDeque(int k) {
        size = k+2;
        front = rear = 0;
    }
    
    bool insertFront(int value) {
        if (isFull()) return false;
        if (isEmpty()){
            rear++;
            rear %= size;
        }
        deque[front--] = value;
        front = (front + size) % size;
        return true;
    }
    
    bool insertLast(int value) {
        if (isFull()) return false;
        if (isEmpty()){
            front = (front-1 + size) % size;
        }
        deque[rear++] = value;
        rear %= size;
        return true;
    }
    
    bool deleteFront() {
        if (isEmpty()) return false;
        front = (front + 1)%size;
        if ((front + 1)%size == rear){
            rear = front;
        }
        
        return true;
    }
    
    bool deleteLast() {
        if (isEmpty()) return false;
        rear = (rear - 1 + size) % size;
        if ((rear - 1 + size)%size == front){
            front = rear;
        }
        return true;
    }
    
    int getFront() {
        if (isEmpty()) return -1;
        int getIdx = (front + 1) % size;
        return deque[getIdx];
    }
    
    int getRear() {
        if (isEmpty()) return -1;
        int getIdx = (rear - 1 + size) % size;
        return deque[getIdx];
    }
    
    bool isEmpty() {
        return front == rear;
    }
    
    bool isFull() {
        return front == (rear + 1) % size;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */