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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *temp1 , *temp2;
        temp1 = temp2 = head;
        int i =0 ;
        while(i < n && temp2){
            cout << temp2->val << endl;
            temp2 = temp2 -> next;
            i+=1;
        }

        while(temp2){
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        if(temp1  == head ){ // first element of the list
            head = head -> next;
        }
        else if(temp1 -> next == NULL){ // last element of the list 
            temp2 = head;
            while(temp2 -> next != temp1){
                temp2 = temp2->next;
            }
            temp2 -> next = NULL;
        }
        else{ // in the middle of the list 
            temp2 = head;
            while(temp2 -> next != temp1){
                temp2 = temp2->next;
            }
            temp2 -> next = temp1 -> next;
        }
        return head;
    }
};
