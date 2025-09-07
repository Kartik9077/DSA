class Solution {
public:
    vector<int>ans;
    vector<int> postorder(Node* root) {
        if(root==NULL) return ans;
        for(auto x:root->children){
            postorder(x);
        }
        ans.push_back(root->val);
        return ans;
    }
};