/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> postorder(Node* root) {
        if (root == nullptr) return {};
        vector<int> ans;
        for(int i = 0 ; i < root->children.size(); i++){
            vector<int> tmp = postorder(root->children[i]);
            ans.insert(ans.end(), tmp.begin(), tmp.end());
        }
        
        ans.push_back(root->val);
        return ans;
    }
};