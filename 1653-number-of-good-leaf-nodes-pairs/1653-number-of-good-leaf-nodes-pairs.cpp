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
    int dist;
    int ans = 0;
    vector<int> traversal(TreeNode* node){
        if (node->left == nullptr && node->right == nullptr) return {1};
        vector<int> v;
        if (node->left){
            v = traversal(node->left);
        }
        if (node->right){
            vector<int> tmp = traversal(node->right);
            for(int i = 0 ; i < tmp.size(); i++){
                for(int j = 0 ; j < v.size(); j++){
                    if (v[j] + tmp[i] <= dist){
                        ans++;
                    }
                }
            }
            v.insert(v.end(), tmp.begin(), tmp.end());
            
        }
        for(int i = 0 ; i < v.size(); i++){
            v[i] += 1;
        }
        return v;
    }
    int countPairs(TreeNode* root, int distance) {
        dist = distance;
        traversal(root);
        return ans;
    }
};