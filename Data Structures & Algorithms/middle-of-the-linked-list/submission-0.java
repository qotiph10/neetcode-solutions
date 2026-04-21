/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode middleNode(ListNode head) {
        ListNode dummy = new ListNode(-1,head);
        ListNode first = dummy;
        ListNode second = head;
        int n = 0;
        while(first.next != null){
                first = first.next;
                n+=1;
        } 
        System.out.print(n);
        n/=2;
        while(n > 0){
            second = second.next;
            n-=1;
        }
        return second;
    }
}