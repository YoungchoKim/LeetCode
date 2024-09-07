/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    vector<int> listNode;
    int pi[100];
    int match;
    bool traversal(TreeNode* root, int match){
        if (match == listNode.size()) return true;
        if(root == nullptr) return false;
        while(match != 0 && root->val != listNode[match]){
            match = pi[match -1];
        }
        if(root->val == listNode[match]){
            match++;
        }
        if (traversal(root->left, match)){
            return true;
        }
        if (traversal(root->right, match)){
            return true;
        }
        return false;
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        while(head){
            listNode.push_back(head->val);
            head = head->next;
        }
        match = 0;
        for(int i = 1; i < listNode.size(); i++){
            while(match != 0 && listNode[i] != listNode[match]){
                match = pi[match-1];
            }
            if(listNode[i] == listNode[match]){
                match++;
            }
            pi[i] = match;
        }
        for(int i = 0 ; i < listNode.size(); i++){
            cout << listNode[i] << " " << pi[i] << endl;
        }
        if (traversal(root, 0)){
            return true;
        }
        return false;
    }
};