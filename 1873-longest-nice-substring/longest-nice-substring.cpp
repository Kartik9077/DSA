class Solution {
public:
    string longestNiceSubstring(string s) {
        int n = s.size();
        if(n<2) return "";
        unordered_set<char> uset;
        for(int i=0;i<n;i++){
            uset.insert(s[i]);
        }
        for(int i=0;i<n;i++){
            if(uset.count(tolower(s[i])) == true && uset.count(toupper(s[i]))==true) continue;
            string prev = longestNiceSubstring(s.substr(0,i));
            string next = longestNiceSubstring(s.substr(i+1));

            return prev.size() >= next.size() ? prev : next;
        }
        return s;
    }
};