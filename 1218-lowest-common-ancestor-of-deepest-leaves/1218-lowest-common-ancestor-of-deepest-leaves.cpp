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
    int maxDepth = -1;
    TreeNode* parent[1001];
    vector<TreeNode*> list;
    void traversal(TreeNode* root, int depth){
        if(root == nullptr) return;
        if(maxDepth < depth){
            maxDepth = depth;
            list.clear();
            list.push_back(root);
        } else if(maxDepth == depth){
            list.push_back(root);
        }
        if(root->left) parent[root->left->val] = root;
        if(root->right) parent[root->right->val] = root;
        traversal(root->left, depth + 1);
        traversal(root->right, depth + 1);
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        traversal(root, 0);
        
        while(true){
            if (list.size() == 1) return list[0];
            vector<TreeNode*> tmp;
            bool success = true;
            int goal = parent[list[0]->val]->val;
            for(int i = 0 ; i < list.size(); i++){
                tmp.push_back(parent[list[i]->val]);
                if(goal != parent[list[i]->val]->val){
                    success = false;
                }
            }
            if(success) return tmp[0];
            list.clear();
            list = tmp;
        }
        return nullptr;
    }
};