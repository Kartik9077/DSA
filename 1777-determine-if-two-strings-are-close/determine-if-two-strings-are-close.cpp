class Solution {
public:
    bool closeStrings(string w1, string w2) {
        if(w1.size()!=w2.size())return 0;
        vector<int>arr(26,0),brr(26,0);
        for(int i=0;i<w1.size();i++){
            arr[w1[i]-'a']++;
            brr[w2[i]-'a']++;
        }
        for(int i=0;i<26;i++)
        {
            if(arr[i]==0&&brr[i]>0 || arr[i]>0&&brr[i]==0)return 0;

        }
        sort(arr.begin(),arr.end());sort(brr.begin(),brr.end());
        for(int i=0;i<26;i++){
            if(arr[i]!=brr[i])return 0;
        }
        return 1;
    }
};