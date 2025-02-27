class Solution {
public:
    int ans = 0;
    bool checkNum(int n, vector<int>& arr){
        int l = 0;
        int r = arr.size() - 1;
        while(l <= r){
            int mid = (l + r) / 2;
            if(arr[mid] == n) return true;
            if(arr[mid] < n){
                l = mid + 1;
            } else{
                r = mid - 1;
            }
        }
        return false;
    }

    void combi(vector<int>&arr, int cur, int depth, vector<int>& selected){
        if(depth == 2){
            int a =  selected[0];
            int b =  selected[1];
            int cnt = 0;
            while(checkNum(a + b, arr)){
                int t = a + b;
                a = b;
                b = t;
                cnt++;
            }
            if(cnt >= 1){
                ans = max(ans, depth + cnt);
            }
            return;
        }

        for(int i = cur + 1; i < arr.size(); i++){
            selected.push_back(arr[i]);
            combi(arr, i, depth + 1, selected);
            selected.pop_back();
        }
    }
    int lenLongestFibSubseq(vector<int>& arr) {
        vector<int> selected;
        combi(arr, -1, 0, selected);
        return ans;
    }
};