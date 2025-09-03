class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        
        unordered_set<string> unique;
        string valid;

        for(string& s: emails){

            valid.clear();
            short len = s.find('@');

            for(short i = 0; i<len; ++i){
                if(s[i]=='+') break;
                if(s[i]!='.') valid+=s[i];
            }

            valid+=s.substr(len);
            unique.insert(valid);

        }
        return unique.size();
    }
};