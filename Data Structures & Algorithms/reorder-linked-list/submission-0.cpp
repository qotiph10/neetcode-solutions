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
    void reorderList(ListNode* head) {
        ListNode *ans ,*temp;
        ans = temp = head;
        while(ans ->next != NULL){
            cout << "ans val : " << ans->val << endl;
            while(temp->next != NULL){
                cout<< "temp val : " << temp -> val << endl;
                if(temp->next->next == NULL){
                    ListNode *temp2 = temp -> next; // last node 
                    temp -> next = NULL; // make the node behind the last null
                    temp = temp2; // temp is now in the last node 

                    temp -> next = ans -> next; 
                    ans -> next = temp;
                    if(ans -> next != NULL){
                        ans = ans->next;
                    }
                    break;
                }
                temp = temp->next;  
            }
            if(ans -> next != NULL){
                ans = ans->next;
            }
        }
    }
};
