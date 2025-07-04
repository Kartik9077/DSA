/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
   int solve(Node* root){
    if(root==nullptr)return 0;
    int maxii=0;
    for(auto it:root->children){
        maxii=max(maxii,solve(it));
    }
    return 1+maxii;
  }
    int maxDepth(Node* root) {
       return solve(root);
        
    }
};