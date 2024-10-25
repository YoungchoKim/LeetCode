struct _node{
    bool tail;
    _node* next[27];
    _node(){
        tail = false;
        for(int i = 0 ; i< 27;i++){
            next[i] = nullptr;
        }
    }
};




class Solution {
public:
    _node trie;
    void insert(string s){
        _node* ptr = &trie;
        for (char c : s){

            int idx = c == '/' ? 26 : c - 'a';
            if(ptr->next[idx] == nullptr){
                ptr->next[idx] = new _node();
            }
            ptr = ptr->next[idx];
        }
        ptr->tail = true;
    }
    void traversal(_node* root, string s, vector<string>& ans){
        if (root == nullptr) return;
        for(int i = 0; i < 26; i++){
            traversal(root->next[i],s + ""+(char)('a'+i), ans);
        }
        if (root->tail){
            ans.push_back(s);
            return;
        }
        traversal(root->next[26],s + "/", ans);
    }
    vector<string> removeSubfolders(vector<string>& folder) {
        for(string s : folder){
            insert(s);
        }
        vector<string> ans;
        traversal(&trie, "", ans);
        return ans;
    }
};