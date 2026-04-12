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
        ListNode* reverseList(ListNode* head) {
            stack<int> s;
            ListNode *temp = new ListNode() , *newHead = new ListNode(); 
            temp = head;
            while(temp != NULL){
                s.push(temp->val); 
                temp = temp-> next;
            }
            temp = newHead;
            while(!s.empty()){
                temp->next = new ListNode(s.top());
                s.pop();
                temp = temp->next;
            }
            return newHead->next;
        }
};
