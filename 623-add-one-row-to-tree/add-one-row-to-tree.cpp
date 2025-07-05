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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(!root) return root;
        queue<pair<TreeNode*, int> > q;
        if(depth == 1) {
            TreeNode* newRoot = new TreeNode(val, root, nullptr);
            return newRoot;
        }
        q.push({root, 1});
        while(!q.empty()){
            auto [curr, dep] = q.front();
            q.pop();

            if(dep == depth - 1){
                TreeNode* leftNode = new TreeNode(val, curr->left, nullptr);
                TreeNode* rightNode = new TreeNode(val, nullptr, curr->right);
                curr->left = leftNode;
                curr->right = rightNode;
            }
            if(curr->left != nullptr){
                q.push({curr->left, dep+1});
            }
            if(curr->right != nullptr){
                q.push({curr->right, dep+1});
            }
        }
        return root;
        
    }
};