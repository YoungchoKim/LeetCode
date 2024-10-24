struct _vector{
    int size;
    int capacity;
    int* arr;
    _vector(){
        size = 0;
        capacity = 2;
        arr = new int[capacity];
    }
    void push(int a){
        if (size == capacity){
            capacity *= 2;
            int* tmp = new int[capacity];
            for(int i = 0 ; i < size;  i++){
                tmp[i] = arr[i];
            }
            delete[] arr;
            arr = tmp;
        }
        arr[size++] = a;
    }
    bool del(int v){
        for(int i = 0 ; i < size; i++){
            if(arr[i] == v){
                arr[i] = arr[--size];
                return true;
            }
        }
        return false;
    }
    int operator[](int idx){
        return arr[idx];
    }
};


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    _vector v[101];
public:
    void addTraversal(TreeNode* root){
        if (root == nullptr) return;
        v[root->val].push(root->left == nullptr ? -1:root->left->val );
        v[root->val].push(root->right == nullptr ? -1 : root->right->val);
        addTraversal(root->left);
        addTraversal(root->right);
    }
    bool delTraversal(TreeNode* root){
        if(root == nullptr) return true;
        if (!v[root->val].del(root->left == nullptr ? -1 : root->left->val)){
            return false;
        }
        if (!v[root->val].del(root->right == nullptr ? -1 : root->right->val)){
            return false;
        }
        if(!delTraversal(root->left)){
            return false;
        }
        if(!delTraversal(root->right)){
            return false;
        }
        return true;
    }
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        addTraversal(root1);
        if(!delTraversal(root2)){
            return false;
        }
        for(int i = 0 ; i < 101; i++){
            if(v[i].size > 0) return false;
        }
        return true;
    }
};