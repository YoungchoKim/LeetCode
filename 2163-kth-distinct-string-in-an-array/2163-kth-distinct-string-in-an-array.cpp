class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> m;
        for(int i = 0 ; i < arr.size(); i++){
            m[arr[i]]++;
        }
        int K = 0;
        for(int i = 0 ; i < arr.size(); i++){
            if(m[arr[i]] == 1){
                K++;
                if(k == K) return arr[i];
            }
        }
        return "";
    }
};