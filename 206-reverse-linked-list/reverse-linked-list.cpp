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
    ListNode* reverseList(ListNode* head) {
        vector<int>arr;
        ListNode *check=head;
        while(check)
        {
            arr.push_back(check->val);
            check=check->next;

        }
        check=head;
        int i=arr.size()-1;
        while(check)
        {
            check->val=arr[i];
            i--;
            check=check->next;
        }
        return head;
    }
};