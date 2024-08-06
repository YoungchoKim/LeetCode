class Solution {
public:
    int word_cnt[26];
    int sortedAlphabet[26];
    int tmp[26];
    void merge(int l, int mid, int r){
        int i = l;
        int j = mid + 1;
        int cur = i;
        while(i <= mid && j <= r){
            if(word_cnt[sortedAlphabet[i]] > word_cnt[sortedAlphabet[j]]){
                tmp[cur++] = sortedAlphabet[i++];
            } else {
                tmp[cur++] = sortedAlphabet[j++];
            }
        }
        while(i <= mid){
            tmp[cur++] = sortedAlphabet[i++];
        }
        for(i = l; i < cur; i++){
            sortedAlphabet[i] = tmp[i];
        }
    }
    void merge_sort(int l, int r){
        if(l >= r) return;
        int mid = (l + r) / 2;
        merge_sort(l ,mid);
        merge_sort(mid+1, r);
        merge(l, mid, r);
    }
    int minimumPushes(string word) {
        int min_cnt = 0;
        for(int i = 0 ; i < word.size(); i++){
            word_cnt[word[i] - 'a']++;
        }
        for(int i = 0 ; i < 26; i++){
            sortedAlphabet[i] = i;
        }
        merge_sort(0, 25);
        int buttonCnt = 0;
        int ans = 0;
        for(int i = 0 ; i < 26; i++){
            int c = sortedAlphabet[i];
            if (word_cnt[c] == 0) break;
            int click_cnt = buttonCnt / 8 + 1;
            ans += click_cnt*word_cnt[c];
            buttonCnt++;
        }
        return ans;
    }
};