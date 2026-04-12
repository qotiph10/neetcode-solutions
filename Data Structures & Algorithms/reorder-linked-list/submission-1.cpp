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
        vector<ListNode*> nodes;
        ListNode* temp = head;
        int j = 0;
        while(temp){
            //cout << temp->val << endl;
            nodes.push_back(temp);
            j+=1;
            temp = temp->next;
        }
        int i = 0, n = j , order = 0;
        //cout << j << endl;
        j-=1;
        while(i != j){
            if(order % 2 == 0){
                nodes[i]->next = nodes[j];
                //cout << nodes[i]->val << "->" << nodes[j]->val << endl;
                i+=1;
            }
            else{
                nodes[j]->next = nodes[i];
                //cout << nodes[j]->val << "->" << nodes[i]->val << endl;
                j-=1;
            }
            order+=1;
        }
        nodes[j]->next = NULL;
        //cout <<nodes[n-1]->val << endl;
        head = nodes[0];
    }
};
