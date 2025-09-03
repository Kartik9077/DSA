class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int a[26]={0};

        for(int i=0;i<text.size();i++){
          a[text[i]-'a']++;
        }     
          int mini=min(a[0],a[1]);
           mini=min(a[13],mini);
          int maxi=min(a[11],a[14])/2;
          return min(mini,maxi);
    }
};