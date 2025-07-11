class Solution {
public:
    int maxVowels(string s, int k) {
        int ans=0;
         if(s.size()<k)return 0;
         int i=0,curr=0;
         while(i<=k-1){
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')curr++;
            i++;
         }
         int j=0;
         ans=curr;
         while(i<s.size()){
             if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')curr++;
             if(s[j]=='a'||s[j]=='e'||s[j]=='i'||s[j]=='o'||s[j]=='u')curr--;
             ans=max(ans,curr);
             i++;j++;
         }
         return ans;

        
    }
};