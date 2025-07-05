class Solution {
public:
    bool NiceSub(string &sub){
        unordered_set<char> chars(sub.begin(),sub.end());
        for(char i : sub){
            if(chars.find(tolower(i)) == chars.end() || chars.find(toupper(i)) == chars.end()){
                return false;
            }
        }
        return true;
    }
    string longestNiceSubstring(string s) {
        string res = "";
        int maxlen = 0;
        for(int i=0; i<s.size(); i++){
            for(int j=i+1; j<=s.size(); j++){
                string sub = s.substr(i,j-i);
                if(NiceSub(sub) && sub.size() > maxlen){
                    res = sub;
                    maxlen = sub.size();
                }
            }
        }
        return res;
    }
};