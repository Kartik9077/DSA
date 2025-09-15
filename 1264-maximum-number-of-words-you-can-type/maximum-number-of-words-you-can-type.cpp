class Solution {
public: 
bool check(string a,string b){
    for(auto it:a){
        if(b.find(it)!=string::npos)return 0;
    }
    return 1;

}
    int canBeTypedWords(string text, string br) {
        unordered_set<char>st;int ans=0;
        for(auto it:br)st.insert(it);
        int j=0,i=0;string k;
        for(i;i<text.size();i++){
            if(text[i]!=' ')k+=text[i];
           else {
               if(check(k,br))ans+=1;
               k="";
             }
        }
         if(check(k,br))ans+=1;
    return ans;
    }
};