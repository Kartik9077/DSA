class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        for(int i = 1; i < s.length()/2 + 1; i++){
            if(s.length()%i!=0) continue;
            bool thiscanwork = true;
            for(int j = 0; j < s.length()/i - 1; j++){
                for(int k = 0; k < i; k++){
                if(s[k+j*i] != s[k+j*i+i])  {thiscanwork = false; break;}
                }
            }
                if(thiscanwork) return true;
        }
        return false;
    }
};