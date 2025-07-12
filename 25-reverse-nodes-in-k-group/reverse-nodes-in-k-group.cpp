class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) { 
        ListNode* node = head;
        int count = 0;
        while (node != NULL && count < k) {
            node = node->next;
            count++;
        } 
        if (count < k)return head; 
        ListNode* next = NULL;
        ListNode* curr = head;
        ListNode* prev = NULL;
        int cnt = 0; 
        while(curr != NULL && cnt < k) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            cnt++;
        } 
        if(next != NULL) {
            head->next = reverseKGroup(next, k);
        } 
        return prev;
    }
};