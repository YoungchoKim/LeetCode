class Solution {
public:
    int rightMin[10];
    vector<int> st;
    int maxChunksToSorted(vector<int>& arr) {
        int ans = 0;
        for(int i = arr.size()-1; i >= 0; i--){
            if(st.empty()){
                st.push_back(arr[i]);
                rightMin[i] = 100000000;
            } else if(arr[i] < st.back()){
                rightMin[i] = st.back();
                st.push_back(arr[i]);
            } else{
                rightMin[i] = st.back();
            }
        }
        int leftMax = 0;
        for(int i = 0 ; i < arr.size(); i++){
            leftMax = max(leftMax, arr[i]);
            if(leftMax <= rightMin[i]){
                ans++;
            }
        }
        return ans;
    }
};