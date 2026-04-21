/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        Map<ListNode,Boolean> mp = new HashMap<>();
        ListNode temp1 = headA , temp2 = headB;
        while(temp1 != null || temp2 != null){
            if(mp.get(temp1) != null || mp.get(temp2) != null || temp1 == temp2){
                return mp.get(temp1) != null ? temp1 : temp2;
            }
            if(temp1 != null){
                mp.put(temp1 , true);
                temp1 = temp1.next != null ? temp1.next : null;
            }
            if(temp2 != null){
                mp.put(temp2 , true);
                temp2 = temp2.next != null ? temp2.next : null;
            }
        }

        return null;
    }
}