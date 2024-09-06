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
    set<int> s;
    ListNode* ans;
    void traversal(ListNode* head){
        if (head == nullptr) return;
        traversal(head->next);
        if( s.find(head->val) != s.end()) return;

        ListNode* temp = new ListNode(head->val, ans);
        ans = temp;
    }
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        for(int i = 0 ; i < nums.size(); i++){
            s.insert(nums[i]);
        }
        traversal(head);
        return ans;    
    }
};