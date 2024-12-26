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
    vector<int> equalLevelNode[100001];
    void traversal(TreeNode* root, int level){
        if(root == nullptr) return;
        equalLevelNode[level].push_back(root->val);
        traversal(root->left, level + 1);
        traversal(root->right, level + 1);
    }
    int minimumOperations(TreeNode* root) {
        traversal(root, 0);
        int ans = 0;
        for(int i = 0 ; i <= 100000; i++){
            if(equalLevelNode[i].size() == 0) break;
            unordered_map<int, int> m;
            vector<int> sorted;
            for(int j = 0 ; j < equalLevelNode[i].size(); j++){
                sorted.push_back(j);
            }
            sort(sorted.begin(), sorted.end(), [&](int a, int b){
                return equalLevelNode[i][a] < equalLevelNode[i][b];
            });
            for(int j = 0; j < sorted.size(); j++){
                m[sorted[j]] = j;
            }
            for(int j = 0; j < sorted.size(); j++){
                if(equalLevelNode[i][sorted[j]] != equalLevelNode[i][j]){
                    ans++;
                    int t = equalLevelNode[i][sorted[j]];
                    equalLevelNode[i][sorted[j]] = equalLevelNode[i][j];
                    equalLevelNode[i][j] = t;

                    sorted[m[j]] = sorted[j];
                    m[sorted[j]] = m[j];
                }
            }
        }
        return ans;
    }
};