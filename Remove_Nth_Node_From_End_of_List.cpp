class Solution {
public:
    ListNode * removeNthFromEnd(ListNode * head, int n) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head; //To avoid edge case when the node to delete is actually head
        ListNode* slow = dummy;
        ListNode* fast = dummy;

        for(int i = 1; i<= n+1; i++) {
            fast = fast->next;
        }

        while(fast) {
            fast = fast->next;
            slow = slow->next;
        }

        slow->next = slow->next->next;

        return dummy->next;
    }
};
