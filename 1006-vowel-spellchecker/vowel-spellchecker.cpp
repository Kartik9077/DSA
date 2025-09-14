class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string>st;
        for(auto it:wordlist)st.insert(it);
        unordered_map<string,vector<string>>mpp;
        for(auto it:wordlist){
            string lower=it;
            transform(lower.begin(),lower.end(),lower.begin(),::tolower);
            mpp[lower].push_back(it);
        }
        vector<string>ans;
        for(auto it:queries){
            if(st.find(it)!=st.end()){ans.push_back(it);continue;}
             transform(it.begin(),it.end(),it.begin(),::tolower);
          if(mpp.find(it)!=mpp.end()){
              ans.push_back(mpp[it][0]);
        }
            else{
                bool sd=0;
                for(int j=0;j<wordlist.size();j++){
                    bool r=0;
                    if(wordlist[j].size()!=it.size())continue;
                     for(int l=0;l<wordlist[j].size();l++)
                     {
                        if(tolower(wordlist[j][l])==tolower(it[l]))continue;
                        char c=tolower(wordlist[j][l]),z=tolower(it[l]);
                        if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u' )c='*';
                        if(z=='a'||z=='e'||z=='i'||z=='o'||z=='u')z='*';
                        if(c==z)continue;
                        else {r=1;break;}
                     }
                     if(r==0){sd=1;ans.push_back(wordlist[j]);break;}
                }
        
            if(sd==0)ans.push_back("");
            }
        }
        return ans;
    }
};