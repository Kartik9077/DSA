class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if(s.size()<11)return {};
        vector<string>ans;
         unordered_map<string,int>mpp;
         string a="";
         for(int i=10;i<=s.size();i++)
         {
            int j=i-10;
           a=s.substr(j,10);
            mpp[a]++;
            a="";
         }
         for(auto it:mpp)if(it.second>1)ans.push_back(it.first);
         return ans;
    }
};