/*
 * @lc app=leetcode id=21 lang=csharp
 *
 * [21] Merge Two Sorted Lists
 */

// @lc code=start

 public class ListNode {
     public int val;
     public ListNode next;
     public ListNode(int val=0, ListNode next=null) {
         this.val = val;
         this.next = next;
     }
 }
public class Solution {
    public ListNode MergeTwoLists(ListNode list1, ListNode list2) {
        if (list1 == null && list2 == null) return null;

        // var newNodes = new ListNode[100];
        // int n = 0;

        ListNode merged = new ListNode();
        var tail = merged;

        while (list1 != null && list2 != null)
        {
            if (list1.val < list2.val)
            {
                tail.val = list1.val;
                list1 = list1.next;
            }
            else
            {
                tail.val = list2.val;
                list2 = list2.next;
            }
            tail.next = new ListNode();
            tail = tail.next;
        }

        var remaining = list1 != null ? list1 : list2;
        tail.val = remaining.val;
        tail.next = remaining.next;

        return merged;
    }
}
// @lc code=end