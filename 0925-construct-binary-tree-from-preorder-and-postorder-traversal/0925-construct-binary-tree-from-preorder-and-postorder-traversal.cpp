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
    
    TreeNode* traversal(TreeNode* root, vector<int>& preorder, int& preIdx, vector<int>& postorder, int& posIdx){
        if(preIdx >= preorder.size()) return nullptr;
        root = new TreeNode(preorder[preIdx]);

        if(root->val == postorder[posIdx]){
            posIdx++;
            return root;
        }

        ++preIdx;
        root->left = traversal(root->left, preorder, preIdx, postorder, posIdx);
        if(root->left == nullptr){
            preIdx--;
        }
        if(root->val == postorder[posIdx]){
            posIdx++;
            return root;
        }
        ++preIdx;
        root->right = traversal(root->right, preorder, preIdx, postorder, posIdx);
        if(root->left == nullptr){
            preIdx--;
        }
        if(root->val == postorder[posIdx]){
            posIdx++;
        }
        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int preIdx = 0;
        int posIdx = 0;
        return traversal(nullptr, preorder, preIdx, postorder, posIdx);
    }
};