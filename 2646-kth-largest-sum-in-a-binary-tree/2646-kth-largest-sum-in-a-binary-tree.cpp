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
public:
    long long arr[100001];
    long long tmp[100001];
    int maxDepth = 0;
    void merge(int l, int mid, int r){
        int i = l;
        int j = mid + 1;
        int cur = i;
        while(i <= mid && j <= r){
            if(arr[i] >= arr[j]){
                tmp[cur++] = arr[i++];
            } else{
                tmp[cur++] = arr[j++];
            }
        }
        while(i <= mid){
            tmp[cur++] = arr[i++];
        }
        for(i = l; i < cur; i++){
            arr[i] = tmp[i];
        }
    }
    void merge_sort(int l, int r){
        if(l >= r) return;
        int mid = (l + r) / 2;
        merge_sort(l, mid);
        merge_sort(mid+1, r);
        merge(l, mid, r);
    }
    void traversal(TreeNode* root, int depth){
        if (root == nullptr) return;
        maxDepth = max(maxDepth, depth);
        arr[depth] += root->val;
        traversal(root->left, depth+1);
        traversal(root->right, depth+1);
    }
    long long kthLargestLevelSum(TreeNode* root, int k) {
        traversal(root, 0);
        if (maxDepth + 1 < k){
            return -1;
        }
        merge_sort(0, 100000);
        return arr[k-1];
    }
};