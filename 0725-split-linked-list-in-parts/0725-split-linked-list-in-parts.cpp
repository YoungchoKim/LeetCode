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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* ptr = head;
        vector<int> arr;
        vector<ListNode*> ans;
        while(ptr){
            arr.push_back(ptr->val);
            ptr = ptr->next;
        }
        int N = arr.size();
        int more = arr.size() % k;
        int arrIdx = 0;
        for(int i = 0 ; i < k ; i++){
            ListNode* tmp = nullptr;
            ListNode* ptr;
            for(int j = 0; j < N / k; j++){
                if (tmp == nullptr) {
                    tmp = new ListNode(arr[arrIdx++]);
                    ptr = tmp;
                } else{
                    ptr->next = new ListNode(arr[arrIdx++]);
                    ptr = ptr->next;
                }
            }
            if (more){
                if (tmp == nullptr) {
                    tmp = new ListNode(arr[arrIdx++]);
                    ptr = tmp;
                } else{
                    ptr->next = new ListNode(arr[arrIdx++]);
                    ptr = ptr->next;
                }
                more--;
            }
            ans.push_back(tmp);
        }

        return ans;
    }
};