class Solution {
public:
    int possibleStringCount(string word) {
        int res=0;
    for(int i=0;i<word.size()-1;i++){
        if(word[i]==word[i+1])res++;
    }
    return res+1;
    }
};