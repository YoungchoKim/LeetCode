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
    int _gcd(int a, int b){
        if(a % b == 0) return b;
        return _gcd(b, a%b);
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* ptr = head;
        while(ptr->next != nullptr){
            int a = ptr->val;
            int b = ptr->next->val;
            ListNode* newNode = new ListNode(_gcd(a, b), ptr->next);
            ptr->next = newNode;
            ptr = newNode->next;
        }
        return head;
    }
};