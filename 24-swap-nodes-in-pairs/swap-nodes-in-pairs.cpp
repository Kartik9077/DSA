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
    ListNode* swapPairs(ListNode* head) {
        ListNode* mover=head;
         ListNode* prev=NULL;
         int count=1;
         while(mover)
         {if(count%2==0)
         {
        swap(mover->val,prev->val);

         }
         prev=mover;
         mover=mover->next;
            count++;
         }
         return head;

    }
};