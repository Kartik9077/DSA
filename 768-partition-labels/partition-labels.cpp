class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int>res;
        unordered_map<char,int>mp;
       for(int i=0;i<s.size();i++){
        mp[s[i]]=i;
       }
       int st=0,end=0;
       for(int i=0;i<s.size();i++){
        end=max(end,mp[s[i]]);
        if(i==end){
            res.push_back(end-st+1);
            st=end+1;

        }

       }
       return res;


    }
};