class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(),folder.end());
        vector<string> ans;
        ans.push_back(folder[0]);
        string prev = folder[0];
        for(int i=1;i<folder.size();i++){
            int l = prev.size();
            if(folder[i].substr(0,l)==prev and folder[i].size()>l and folder[i][l]=='/')
            {
                continue;
            }
            else
            {
                ans.push_back(folder[i]);
                prev = folder[i];
            }
        }
        return ans;
    }
};