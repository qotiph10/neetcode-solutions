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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* newHead = new ListNode(0 , NULL) , *temp;
        temp = newHead;
        int c = 0;
        while(true){
            int minIndex , minVal = INT_MAX;
            c = 0;
            for(int i =0 ; i < lists.size() ;i++){
                if(lists[i]){
                    if(minVal >= lists[i]->val){
                        minIndex = i;
                        minVal = lists[i]->val;
                    }
                }
                else{
                    c+=1;
                }
            }
            if(c == lists.size()){
                break;
            }
            c+=1;
            cout << lists[minIndex] -> val << endl;
            temp -> next = lists[minIndex];
            lists[minIndex] = lists[minIndex] -> next;
            temp = temp -> next;
        }
        temp -> next = NULL;
        return newHead -> next;
    }
};
