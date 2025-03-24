class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        int l = meetings[0][0];
        int r = meetings[0][1];
        int ans = 0;
        ans += l - 1;
        for(int i = 1 ; i < meetings.size(); i++){
            int ll = meetings[i][0];
            int rr = meetings[i][1];
            if(r < ll){
                ans += ll - r - 1;
            }
            r = max(r, rr);
        }
        ans += days - r;
        return ans;
    }
};