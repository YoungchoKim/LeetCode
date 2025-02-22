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
    TreeNode* makeTree(TreeNode* root, int depth, string& traversal, int &processed){
        if(processed == traversal.size()){
            return nullptr;
        }
        
        int i = processed;
        int curDepth = 0;
        while(i < traversal.size() && traversal[i] == '-'){
            i++;
            curDepth++;
        }
        if(curDepth < depth){
            return nullptr;
        }
        int val = 0;
        while(i < traversal.size() && traversal[i] >= '0' && traversal[i] <= '9'){
            val *= 10;
            val += traversal[i] - '0';
            i++;
        }
        processed = i;
     
        root = new TreeNode();
        root->val = val;
        root->left = makeTree(root->left, depth+1, traversal, processed);
        root->right = makeTree(root->right, depth+1, traversal, processed);
        return root;
    }
    TreeNode* recoverFromPreorder(string traversal) {
        int processed = 0;
        TreeNode* root = makeTree(root, 0, traversal, processed);
        return root;
    }
};