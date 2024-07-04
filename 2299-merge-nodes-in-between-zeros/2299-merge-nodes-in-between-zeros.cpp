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
    
    ListNode* mergeNodes(ListNode* head) {
        ListNode* answer = nullptr;
        ListNode* ptr2;
        int sum = 0;
        for (ListNode* ptr = head-> next; ptr != nullptr; ptr = ptr->next){
            if(ptr->val == 0){
                if (answer == nullptr){
                    answer = new ListNode(sum);
                    ptr2 = answer;
                } else {
                    ptr2->next = new ListNode(sum);
                    ptr2 = ptr2->next;
                }
                sum = 0;
            } else {
                sum += ptr->val;
            }
        }
        return answer;
    }
};