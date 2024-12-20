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
    const static int TREE_SIZE = (1<<14) + 1;
    int tree[TREE_SIZE];
    int maxSize = 0;
    void init(TreeNode* root, int idx){
        if(root == nullptr){
            return;
        }
        maxSize = (maxSize, idx);
        tree[idx] = root->val;
        init(root->left, idx*2);
        init(root->right, idx*2 + 1);
    }
    void reverse(int level, int idx){
        if(idx > maxSize) return;
        int idx2 = idx << 1;
        if(level & 1){
            int l = idx;
            int r = idx2 - 1;
            while(l < r){
                int t = tree[l];
                tree[l] = tree[r];
                tree[r] = t;
                l++;
                r--;
            }
        }
        reverse(level+1, idx2);
    }
    TreeNode* changeValue(TreeNode* root, int idx){
        if(root == nullptr) return nullptr;
        root->val = tree[idx];
        changeValue(root->left, idx*2);
        changeValue(root->right, idx*2 + 1);
        return root;
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        init(root, 1);
        reverse(0, 1);
        return changeValue(root, 1);
    }
};