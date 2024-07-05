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
    int prev = -1;
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* ptr;
        vector<int> ansVector;
        int minVal = 1234567890;
        int idx;
        for(ptr = head, idx=0; ptr->next != nullptr; ptr = ptr->next, idx++){
            if(prev == -1){
                prev = ptr->val;
                continue;
            }
            if (ptr->next->val > ptr->val && prev > ptr->val){
                if (!ansVector.empty()){
                    minVal = min(minVal, idx - ansVector.back());
                }
                ansVector.push_back(idx);
            } else if(ptr->next->val < ptr->val && prev < ptr->val){
                if (!ansVector.empty()){
                    minVal = min(minVal, idx - ansVector.back());
                }
                ansVector.push_back(idx);
            }
            prev = ptr->val;
        }
        if (ansVector.size() < 2) return {-1, -1};
        return {minVal, ansVector.back() - ansVector[0]};
    }
};