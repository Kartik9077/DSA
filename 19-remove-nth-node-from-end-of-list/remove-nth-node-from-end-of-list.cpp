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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        int count=0;
   ListNode *temp=head;
   while(temp)
   {
    count++;
    temp=temp->next;
   } 
   int no=count-n;
  
   ListNode* prev=NULL;
   ListNode* curr=head;
  if(no==0)
   {
    head=head->next;
    return head;
   }
   while(no)
   {
    prev=curr;
    curr=curr->next;
  no--;
   } 
   prev->next=curr->next;
   delete(temp);
   
return head;
    }
};