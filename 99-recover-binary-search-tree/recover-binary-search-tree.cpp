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
private:
TreeNode* prev;
TreeNode* first;
TreeNode*last;
TreeNode*middle;
private:
void inorder(TreeNode*root){
        if(root==NULL)return ;
        inorder(root->left);
        if(prev!=NULL && root->val<prev->val){
            if(first==NULL){
                first=prev;
                middle=root;
            }
            else{
                last=root;
            }
        }
            prev=root;
            inorder(root->right);

    }
public:
    
    void recoverTree(TreeNode* root) {
    if(root==NULL)return ;
    last=middle=first=NULL;
    prev=new TreeNode(INT_MIN);
    inorder(root);
    if(last && first)swap(first->val,last->val);
    else swap(first->val,middle->val);
    }
};
    