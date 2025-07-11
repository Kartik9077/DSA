class Solution {
public:
    string reverseVowels(string s) {
        vector<char>arr;
        for(int i=0;i<s.length();i++){
            if(s[i]=='a'||s[i]=='A'||s[i]=='e'||s[i]=='E'||s[i]=='I'||s[i]=='i'||s[i]=='o'||s[i]=='O'||s[i]=='u'||s[i]=='U'){
                arr.push_back(s[i]);

            }
        }
        reverse(arr.begin(),arr.end());
        int j=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='a'||s[i]=='A'||s[i]=='e'||s[i]=='E'||s[i]=='I'||s[i]=='i'||s[i]=='o'||s[i]=='O'||s[i]=='u'||s[i]=='U'){
                s[i]=arr[j];
                j++;
            }
        }
        return s;

        
    }
};