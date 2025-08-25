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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    ListNode* current;
    TreeNode* build(int start, int end){
        if(start>end) return NULL;

        int mid = start + (end - start)/2;

        TreeNode* left = build(start, mid-1);

        TreeNode* root = new TreeNode(current->val);

         root->left = left;

        current = current->next;

        root->right = build(mid + 1, end);

        return root; 
    }

    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) return NULL;

        ListNode* temp = head;
        int i = 0;
        current = head;

        while(temp != NULL){
            i++;
            temp = temp->next;
        }

        return build(0, i-1);

    }
};