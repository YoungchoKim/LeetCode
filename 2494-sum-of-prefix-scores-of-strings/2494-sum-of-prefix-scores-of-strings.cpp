struct trie{
    int score;
    trie* next[26];
    bool tail;
    trie(){
        score = 0;
        for(int i = 0 ; i < 26; i++){
            next[i] = nullptr;
        }
        tail = false;
    }
    ~trie(){
        for(int i = 0 ; i < 26; i++){
            if(next[i] != nullptr) delete next[i];
            next[i] = nullptr;
        }
    }
};

void insert(trie* root, string &s, int s_idx, int size){
    if (s_idx == size) {
        root->tail = true;
        return;
    }
    int idx = s[s_idx]-'a';
    if(root->next[idx] == nullptr){
        root->next[idx] = new trie();
    }
    root->next[idx]->score++;
    insert(root->next[idx], s, s_idx+1, size);
}
int getScore(trie* root, string &s, int s_idx, int size){
    if(s_idx == size) return root->score;
    int idx = s[s_idx] - 'a';
    return root->score + getScore(root->next[idx], s, s_idx + 1, size);
}

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        trie t;
        vector<int> ans;
        for(string word : words){
            insert(&t, word, 0, word.size());
        }
        for(string word : words){
            int score = getScore(&t, word, 0, word.size());
            ans.push_back(score);
        }
        return ans;
    }
};