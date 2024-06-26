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

 // copyright: https://leetcode.com/problems/balance-a-binary-search-tree/solutions/539686/java-c-sorted-array-to-bst-o-n-clean-code/
class Solution {
public:
    vector<TreeNode*> sortedArr;
    void inorderTraverse(TreeNode* root){
        if(root == nullptr) return;
        inorderTraverse(root->left);
        sortedArr.push_back(root);
        inorderTraverse(root->right);
    }
    TreeNode* balanceBST(TreeNode* root) {
        inorderTraverse(root);
        return sortedArrayToBST(0, sortedArr.size() - 1);
    }
    TreeNode* sortedArrayToBST(int start, int end){
        if (start > end) return nullptr;
        int mid = (start + end) / 2;
        TreeNode* root = sortedArr[mid];
        root->left = sortedArrayToBST(start, mid-1);
        root->right = sortedArrayToBST(mid+1, end);
        return root;
    }
};