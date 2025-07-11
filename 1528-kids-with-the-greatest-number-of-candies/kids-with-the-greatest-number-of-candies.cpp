class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& c, int e) {
        int n=*max_element(c.begin(),c.end());
        vector<bool>ans;
        for(auto it:c){
            if(it+e >=n)ans.push_back(1);
            else ans.push_back(0);
        }
        return ans;
    }
};