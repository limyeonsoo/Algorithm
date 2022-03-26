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
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode head = new ListNode();
        ListNode dummyHead = head;
        
        int carry = 0;
        while(l1 != null || l2 != null) {
            int l1Var = l1 == null ? 0 : l1.val;
            int l2Var = l2 == null ? 0 : l2.val;
            
            int sum = l1Var + l2Var + carry;
            carry = sum / 10;
            sum = sum % 10;
            
            dummyHead.next = new ListNode(sum);
            dummyHead = dummyHead.next;
            
            if(l1 != null) l1 = l1.next;
            if(l2 != null) l2 = l2.next;
        }
        if(carry > 0) {
            dummyHead.next = new ListNode(carry);
        }
        return head.next;
    }
}

