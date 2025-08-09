

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>>ans;
        vector<int>temp;
        if(!root)return ans;
        queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        int n=q.size();
        for(int i=0;i<n;i++){
            Node* node=q.front();
            temp.push_back(node->val);
            q.pop();
            for(auto it:node->children)q.push(it);
        }
        ans.push_back(temp);
        temp.clear();
    }
    return ans;
        
    }
};