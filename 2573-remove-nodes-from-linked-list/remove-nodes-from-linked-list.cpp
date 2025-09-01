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
    ListNode* removeNodes(ListNode* head) {
        vector<int>arr;
           ListNode*  temp=head;
           while(temp!=nullptr){
            arr.push_back(temp->val);
            temp=temp->next;
           }
        stack<int>st;
      for(int i=arr.size()-1;i>=0;i--){
        if(st.empty())st.push(arr[i]);
        else if(st.top()>arr[i])continue;
        else st.push(arr[i]);
      }
         ListNode* dummy=new  ListNode(st.top());
         st.pop();
         if(st.size()==0)return dummy;
         temp=dummy;
         while(!st.empty()){
            temp->next=new  ListNode(st.top());
            temp=temp->next;
            st.pop();

         }
         return dummy;
        
        
    }
};