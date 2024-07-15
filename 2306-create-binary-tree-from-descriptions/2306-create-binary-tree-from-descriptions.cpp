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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        map<int, TreeNode*> myMap;
        map<int, int> parentMap;
        int root = descriptions[0][0];
        for(int i = 0 ; i < descriptions.size(); i++){
            int parent = descriptions[i][0];
            int child = descriptions[i][1];
            int isLeft = descriptions[i][2];
            parentMap[child] = parent;
            if (myMap.find(parent) == myMap.end()){
                myMap[parent] = new TreeNode(parent);
            }
            if (myMap.find(child) == myMap.end()){
                myMap[child] = new TreeNode(child);
            }
            if (isLeft == 1){
                myMap[parent]->left = myMap[child];
            } else {
                myMap[parent]->right = myMap[child];
            }
        }
        while(parentMap.find(root) != parentMap.end()){
            root = parentMap[root];
        }
        return myMap[root];
    }
};