class Solution {
public:
    vector<int> h;
    int tmp[1001];
    void merge(int* arr, int l, int mid, int r){
        int i = l;
        int j = mid + 1;
        int cur = l;
        while(i <= mid && j <= r){
            int num1 = arr[i];
            int num2 = arr[j];
            if(h[num1] >= h[num2]){
                tmp[cur++] = arr[i++];
            }else{
                tmp[cur++] = arr[j++];
            }
        }
        while(i <= mid){
            tmp[cur++] = arr[i++];
        }
        for(i = l; i < cur; i++){
            arr[i] = tmp[i];
        }
    }
    void merge_sort(int* arr, int l, int r){
        if (l >= r) return;
        int mid = (l + r) / 2;
        merge_sort(arr, l, mid);
        merge_sort(arr, mid+1, r);
        merge(arr, l, mid, r);
    }

    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        h = heights;
        int* arr = new int[heights.size()];
        for(int i = 0 ; i < heights.size(); i++){
            arr[i] = i;
        }
        merge_sort(arr, 0, heights.size()-1);
        vector<string> ans;
        for(int i = 0 ; i < heights.size(); i++){
            int n = arr[i];
            ans.push_back(names[n]);
        }
        return ans;
    }
};