class Solution {
public:
    bool hasAlternatingBits(int n) {
         string s=bitset<64>(n).to_string();
        s.erase(0, s.find_first_not_of('0'));
        for(int i=0;i<s.size()-1;i++)
            if(s[i]==s[i+1]) return false;
        return true;
    }
};