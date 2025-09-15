class Solution {
public:
    string replaceWords(vector<string>& di, string se) {
        unordered_set<string>st;bool k=0;
        for(auto it:di)st.insert(it);
        string ans="";
        string curr="";
        for(int i=0;i<se.size();i++){
            k=0;
            if(se[i]!=' '){
                curr+=se[i];
                if(st.find(curr)!=st.end()){
                   if(ans!="")ans+=' ';
                    ans+=curr;
                    while(i<se.size()&&se[i]!=' '){k=1;i++;}
                    curr="";
                }
            }
            else {
                k=1;
               if(ans!="")ans+=' ';
                ans+=curr;
                curr="";
            }

        }
        if(k==0){ans+=' ';ans+=curr;}
        return ans;
        

    }
};