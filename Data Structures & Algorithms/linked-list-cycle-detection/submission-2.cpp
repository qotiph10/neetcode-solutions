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
    bool hasCycle(ListNode* head) {
        ListNode *slow , *fast;
        slow = fast = head;
        while(fast != NULL){
            if(fast->next !=NULL){
                if(fast->next->next != NULL){
                    fast = fast->next->next;
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
            
            slow = slow->next;
            cout << "fast:" << fast->val << " slow:" << slow->val << endl;
            if(fast != NULL && slow != NULL){
                if(fast->val == slow->val){
                    return true;
                }
            }
            else{
                    return false;
                }
        }

        return false;
    }
};
