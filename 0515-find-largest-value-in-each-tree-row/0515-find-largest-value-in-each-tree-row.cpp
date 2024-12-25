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
    vector<int> ans;
    void traversal(TreeNode* root, int depth){
        if(root == nullptr) return;
        if(ans.size() == depth){
            ans.push_back(root->val);
        } else{
            ans[depth] = max(ans[depth], root->val);
        }
        traversal(root->left, depth + 1);
        traversal(root->right, depth + 1);
    }
    vector<int> largestValues(TreeNode* root) {
        traversal(root, 0);
        return ans;
    }
};