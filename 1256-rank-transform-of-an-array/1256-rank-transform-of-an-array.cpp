class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> arr2 = arr;
        sort(arr2.begin(), arr2.end());
        unordered_map<int, int> m;
        
        int rank = 0;
        int curNum = -1;
        for(int num : arr2){
            if(curNum == num){
                continue;
            }
            curNum = num;
            rank++;
            m[num] = rank;
        }

        vector<int> ans;
        for(int num: arr){
            ans.push_back(m[num]);
        }
        return ans;
    }
};