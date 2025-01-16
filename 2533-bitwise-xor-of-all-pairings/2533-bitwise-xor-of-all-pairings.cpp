class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n1 = (nums1.size()-1) % 2;
        int n2 = (nums2.size()-1) % 2;
        int ans = 0;
        for(int i = 0 ; i < nums1.size(); i++){
            for(int j = 0 ; j <= n2; j++){
                ans ^= nums1[i];
            }
        }
        for(int i = 0 ; i < nums2.size(); i++){
            for(int j = 0; j <= n1; j++){
                ans ^= nums2[i];
            }
        }
        return ans;
    }
};