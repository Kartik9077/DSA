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
    ListNode* oddEvenList(ListNode* head) {
        if(head==nullptr||head->next==nullptr||head->next->next==nullptr)return head;
        ListNode*  prevOdd=head,*prevEven=head->next,*fixedEven=head->next,*nextOdd = head->next->next;
         while(prevEven && nextOdd) {

            prevEven->next = nextOdd->next;
            nextOdd->next = fixedEven;
            prevOdd->next = nextOdd;
            prevEven = prevEven->next;
            prevOdd = prevOdd->next;
            if(prevEven) nextOdd = prevEven->next;
        }

        return head;
    }
};