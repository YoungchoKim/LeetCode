class Solution {
public:
    string pushDominoes(string dominoes) {
        for(int i = 0 ; i < dominoes.size(); i++){
            if(dominoes[i] == 'L'){
                int j = i-1;
                while(j >= 0 && dominoes[j] == '.'){
                    dominoes.at(j) = 'L';
                    j--;
                }
            } else if(dominoes[i] == 'R'){
                int j = i+1;
                while(j < dominoes.size() && dominoes[j] == '.'){
                    j++;
                }
                if(j >= dominoes.size() || dominoes[j] == 'R'){
                    for(; i < j; i++){
                        dominoes.at(i) = 'R';
                    }
                    if(j < dominoes.size() && dominoes[j] == 'R'){
                        i--;
                    }
                } else{
                    int k = i + 1;
                    int l = j - 1;
                    while(k < l){
                        dominoes.at(k) = 'R';
                        dominoes.at(l) = 'L';
                        k++;
                        l--;
                    }
                    i = j;
                }
            }
        }
        return dominoes;
    }
};