class Solution {
public:
    vector<string> words;
    int isPrefixOfWord(string sentence, string searchWord) {
        words.push_back(sentence);
        for(int i =0; i < sentence.size(); i++){
            if(sentence[i] == ' '){
                words.push_back(sentence.substr(i+1));
            }
        }
        for(int i = 0 ; i < words.size(); i++){
            int j = 0;
            for( ; j < searchWord.size(); j++){
                if(searchWord[j] != words[i][j]){
                    break;
                }
            }
            if(j == searchWord.size()){
                return i + 1;
            }
        }
        return -1;
    }
};