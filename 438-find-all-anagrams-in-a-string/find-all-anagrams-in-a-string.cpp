class Solution {
    bool character_match(string a,string p){
     vector<int>freq(26,0);
     vector<int>window(26,0);
     for(int i=0;i<a.size();i++){
        freq[a[i]-'a']++;
        window[p[i]-'a']++;
     }
          return freq==window;
    }
public:
    vector<int> findAnagrams(string s, string p) {
        if(s.size()<p.size())return {};
    int m=p.length();
    int start=0;vector<int>ans;
    while(start<s.length()-m+1){
        if(character_match(s.substr(start,m),p)){
            ans.push_back(start);
        }
        start++;


    }
    return ans;
        
    }
};