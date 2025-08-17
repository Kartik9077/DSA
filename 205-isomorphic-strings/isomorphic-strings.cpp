class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char>mpp,mpp2;
        for(int i=0;i<s.size();i++){
           if((mpp.find(s[i])!=mpp.end()&& mpp[s[i]]!=t[i])||(mpp2.find(t[i])!=mpp.end()&&mpp2[t[i]]!=s[i]))return 0;
           if(mpp.find(s[i])==mpp.end())mpp[s[i]]=t[i];
           if(mpp2.find(t[i])==mpp.end())mpp2[t[i]]=s[i];
        }
        return 1;
    }
};