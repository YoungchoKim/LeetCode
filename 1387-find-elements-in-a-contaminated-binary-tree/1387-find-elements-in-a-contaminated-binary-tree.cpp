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
class FindElements {
public:
    bool s[2000001] = {0};
    void traversal(TreeNode* root, int val){
        if(root == nullptr) return;
        root->val = val;
        s[val] = true;
        traversal(root->left, val*2 + 1);
        traversal(root->right, val*2 + 2);
    }
    FindElements(TreeNode* root) {
        traversal(root, 0);
    }
    
    bool find(int target) {
        return s[target];
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */