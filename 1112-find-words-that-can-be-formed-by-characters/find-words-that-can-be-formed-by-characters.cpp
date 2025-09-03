class Solution {
public:
   bool check(vector<int>arr,string a){
    for(auto it:a){
        if(arr[it-'a']==0)return 0;
        else arr[it-'a']--;
    }
    return 1;
   }
    int countCharacters(vector<string>& words, string chars) {
        vector<int>arr(26,0);
        for(auto ch:chars){
            arr[ch-'a']++;
        }
        int ans=0;
        for(int i=0;i<words.size();i++){
            vector<int>k=arr;
            if(check(k,words[i]))ans+=words[i].size();
        }
        return ans;
    }
};