/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> ans;
    
    int R, C;
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        int dy[] = {0, 1, 0, -1};
        int dx[] = {1, 0, -1, 0};
        R = m;
        C = n;
        for(int i = 0 ; i < m; i++){
            ans.push_back(vector<int>());
            for(int j = 0; j < n ; j++){
                ans[i].push_back(-1);
            }
        }
        int r = 0;
        int c = 0;
        int dir = 0;
        while(head){
            ans[r][c] = head->val;
            int nr = r + dy[dir];
            int nc = c + dx[dir];
            if (nr < 0 || nr >= R || nc < 0 || nc >= C || ans[nr][nc] != -1){
                dir = (dir + 1) %4;
                nr = r + dy[dir];
                nc = c + dx[dir];
            }
            r = nr;
            c = nc;
            head = head->next;
        }
        return ans;
    }
};