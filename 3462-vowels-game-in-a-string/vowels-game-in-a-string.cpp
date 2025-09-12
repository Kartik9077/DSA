class Solution {
public:
    bool doesAliceWin(string s) {
    int to_vowel=0;
    for(auto it:s)if(it=='a'||it=='e'||it=='i'||it=='o'||it=='u' )to_vowel++;
    if(to_vowel)return 1;
    return 0;
   
    }
};