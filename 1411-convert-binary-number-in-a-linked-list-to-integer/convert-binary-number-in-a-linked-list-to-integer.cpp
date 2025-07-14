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
public: void cal(ListNode* head ,__int128 &n){
    ListNode* temp=head;
    while(temp!=nullptr){
        n*=10;
        n+=temp->val;
        temp=temp->next;
    }

}
    int getDecimalValue(ListNode* head) {
       __int128 n=0;
       cal(head,n);
       int ans=0,i=0;
       while(n>0){
        int rem=n%10;
        ans+=rem*pow(2,i);
        i++;
        n/=10;
       }
       return ans;
        
    }
};