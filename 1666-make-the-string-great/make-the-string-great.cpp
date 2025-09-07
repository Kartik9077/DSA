class Solution {
public:
    string makeGood(string s) {
         string ans="";
        for(int i=0; i<s.size(); i++){
           
            if(!ans.empty() && ans.back()!=s[i] && tolower(ans.back())==tolower(s[i])) ans.pop_back();
            else ans.push_back(s[i]);
             
        }
        return ans;
    }
};