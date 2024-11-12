struct _item{
    int price;
    int beauty;
};

class Solution {
public:
    _item arr[100001];
    _item tmp[100001];
    void merge(int l, int mid, int r){
        int i = l;
        int j = mid + 1;
        int cur = l;
        while(i <= mid & j <= r){
            if(arr[i].price < arr[j].price){
                tmp[cur++] = arr[i++];
            } else if (arr[i].price > arr[j].price){
                tmp[cur++] = arr[j++];
            } else{
                if(arr[i].beauty >= arr[j].beauty){
                    tmp[cur++] = arr[i++];
                } else {
                    tmp[cur++] = arr[j++];
                }
            }
        }
        while(i<= mid){
            tmp[cur++] = arr[i++];
        }
        for(i = l; i < cur; i++){
            arr[i] = tmp[i];
        }
    }
    void merge_sort(int l, int r){
        if(l >= r) return;
        int mid = (l + r) / 2;
        merge_sort(l, mid);
        merge_sort(mid+1, r);
        merge(l, mid, r);
    }
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        for(int i = 0 ; i < items.size(); i++){
            arr[i].price = items[i][0];
            arr[i].beauty = items[i][1];
        }
        merge_sort(0, items.size() - 1);
        int maxBeauty = arr[0].beauty;
        for(int i = 1 ; i < items.size(); i++){
            if(arr[i].beauty < maxBeauty){
                arr[i].beauty = maxBeauty;
            } else {
                maxBeauty = arr[i].beauty;
            }
        }
        vector<int> ansV;
        for(int i = 0 ; i < queries.size(); i++){
            int l = 0;
            int r = items.size() - 1;
            int ans = 0;
            while(l <= r){
                int mid = (l + r ) / 2;
                if (arr[mid].price > queries[i]){
                    r = mid - 1;
                    continue;
                }
                ans = arr[mid].beauty;
                l = mid + 1;
            }
            ansV.push_back(ans);
        }
        return ansV;
    }
};