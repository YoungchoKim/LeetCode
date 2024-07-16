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

vector<int> rootToStart;
vector<int> rootToDest;
vector<char> rootToDestChar;
class Solution {
public:
    bool searchPath(TreeNode* ptr, int dest, vector<int> &path){
        if (ptr == nullptr) return false;
        if (ptr->val == dest) {
            path.push_back(dest);
            return true;
        }
        path.push_back(ptr->val);
        rootToDestChar.push_back('L');
        if (searchPath(ptr->left, dest, path)){
            return true;
        }
        rootToDestChar.pop_back();
        rootToDestChar.push_back('R');
        if (searchPath(ptr->right, dest, path)){
            return true;
        }
        rootToDestChar.pop_back();
        path.pop_back();
        return false;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        rootToStart.clear();
        rootToDest.clear();
        searchPath(root, startValue, rootToStart);
        rootToDestChar.clear();
        searchPath(root, destValue, rootToDest);
        
        string res = "";
        int cnt = 0;
        while(cnt < rootToStart.size() && cnt < rootToDest.size() && rootToStart[cnt] == rootToDest[cnt]) cnt++;
        for(int i = 0; i < rootToStart.size() - cnt; i++){
            res += "U";
        }
        for(int i = cnt-1 ; i < rootToDestChar.size(); i++){
            res += rootToDestChar[i];
        }

        for(int i = 0 ; i < rootToStart.size(); i++){
            cout << rootToStart[i] << " ";
        } 
        cout << endl;
        
        for(int i = 0 ; i < rootToDest.size(); i++){
            cout << rootToDest[i] << " ";
        } 
        for(int i = 0 ; i < rootToDestChar.size(); i++){
            cout << rootToDestChar[i] << " ";
        }
        return res;
    }
};