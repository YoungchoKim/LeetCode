struct node{
    int val;
    struct node *next;
    struct node *prev;
    node(){
        val = -1;
        next = this;
        prev = this;
    }
};




class Solution {
public:
    node head;
    
    void insertLast(int v){
        node* newNode = new node();
        newNode->val = v;
        newNode->prev = head.prev;
        newNode->next = &head;
        head.prev->next = newNode;
        head.prev = newNode;
    }
    node* removeK(node* ptr, int k){
        for(int i = 0 ; i < k; i++){
            if(ptr->next == &head){
                ptr = ptr->next;
            }
            ptr = ptr->next;
        }
        if (ptr->next == &head){
            ptr = ptr->next;
        }
        node* deleteNode = ptr->next;
        ptr->next = deleteNode->next;
        deleteNode->next->prev = ptr;
        // delete deleteNode;
        return ptr;
    }

    int findTheWinner(int n, int k) {
        for(int i = 1; i <= n; i++){
            insertLast(i);
        }
        node* ptr = &head;
        while(n-- > 1){
            ptr = removeK(ptr, k-1);
            cout << ptr->next->val << endl;
        }
        return head.next->val;
    }
};