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
    bool traversal(TreeNode* ptr, vector<TreeNode*> &ans, int target){
        if(ptr == nullptr) return false;
        if(ptr->val ==  target){
            for(int i = 0 ; i < ans.size(); i++){
                if (ans[i] == nullptr) continue;
                if (ans[i]->val == target){
                    ans[i] = nullptr;
                    break;
                }
            }
            if (ptr->left){
                ans.push_back(ptr->left);
            }
            if (ptr->right){
                ans.push_back(ptr->right);
            }
            return true;
        }

        if (traversal(ptr->left, ans, target)){
            ptr->left = nullptr;
        }
        if (traversal(ptr->right, ans, target)){
            ptr->right = nullptr;
        }
        return false;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> ans = {root};
        for(int i = 0 ; i < to_delete.size(); i++){
            for(int j = 0 ; j < ans.size(); j++){
                traversal(ans[j], ans, to_delete[i]);
            }
        }
        vector<TreeNode*> ans2;
        for(int i = 0 ; i < ans.size(); i++){
            if (ans[i] == nullptr) continue;
            ans2.push_back(ans[i]);
        }
        return ans2;
    }
};