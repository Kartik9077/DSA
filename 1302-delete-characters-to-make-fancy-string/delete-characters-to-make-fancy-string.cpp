class Solution {
public:
    string makeFancyString(string s) {
        vector<int>pos;
        for(int i=1;i<s.size()-1;i++)if(s[i-1]==s[i]&&s[i]==s[i+1])pos.push_back(i);

        string ans="";int j=0,i=0;
       while(i<s.size()&&j<pos.size())
        {
            if(i==pos[j]){
                j++;i++;
            }
            else {ans+=s[i];i++;}
            

        }
        while(i<s.size())ans+=s[i++];
        return ans;
    }
};