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
    ListNode* sortList(ListNode* head) {
        map<int,int>mpp;

      ListNode * temp=head;
      while(temp)
      {
      mpp[temp->val]++;
       temp=temp->next;

      }
      
      ListNode * dummyhead=new ListNode (0);
        dummyhead->next=head;
        temp=dummyhead;
       for(auto it: mpp)
        {  while(it.second!=0)
        {

    
          temp->next=new ListNode(it.first);
          
          temp=temp->next;
          it.second-=1;
        }
        }
        return dummyhead->next;
    }
};