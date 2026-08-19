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
    public int pairSum(ListNode head) {
        int index = 0 , size = -1 , ans = 0;
        ListNode temp = head;
        do{
            ListNode temp2 = temp;
            int sum = 0;
            if(size == -1){
                int c = 1;
                while(temp2.next != null){
                    c+=1;
                    temp2 = temp2.next;
                }
                size = c;
                System.out.println("found size:"+size);
            }
            else{
                int i = index;
                while(i != (size - index -1)){
                    temp2 = temp2.next;
                    i+=1;
                }
                System.out.println(index+"<-- twin of -->"+ i );
            }
            sum = temp.val + temp2.val;
            index+=1;
            temp = temp.next;
            ans = Math.max(ans , sum);
        }while(index < size/2);
        return ans;
    }
}