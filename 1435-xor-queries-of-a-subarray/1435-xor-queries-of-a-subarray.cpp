class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> ans;
        for(int i = 1 ; i < arr.size(); i++){
            arr[i] = arr[i] ^ arr[i-1];
        }
        for(int i = 0 ; i < queries.size(); i++) {
            int a = queries[i][0];
            int b = queries[i][1];
            ans.push_back(arr[b] ^ (a-1 < 0 ? 0 : arr[a-1]));
        }
        return ans;
    }
};