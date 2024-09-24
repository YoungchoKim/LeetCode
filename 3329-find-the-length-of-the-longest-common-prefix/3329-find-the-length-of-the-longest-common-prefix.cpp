class Solution {
public:
    set<int> s;
    int getCount(int a){
        int cnt = 0;
        while(a){
            cnt++;
            a /= 10;
        }
        return cnt;
    }
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int ans = 0;
        for(int i = 0 ; i < arr1.size(); i++){
            while(arr1[i]){
                s.insert(arr1[i]);
                arr1[i] /= 10;
            }
        }
        for(int i = 0 ; i < arr2.size(); i++){
            while(arr2[i]){
                if (s.find(arr2[i]) != s.end()){
                    ans = max(ans, getCount(arr2[i]));
                    break;
                }
                arr2[i] /= 10;
            }
        }
        return ans;
    }
};