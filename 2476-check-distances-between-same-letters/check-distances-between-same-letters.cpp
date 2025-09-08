class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        unordered_map<char,vector<int>>mpp;
        for(int i=0;i<s.size();i++){
            mpp[s[i]].push_back(i);
        }
        for(int i=0;i<s.size();i++){
            if(mpp.find(s[i])==mpp.end())continue;
              vector<int>a=mpp[s[i]];
            if((a[1]-a[0]-1)==distance[s[i]-'a'])continue;
            else return 0;
        }
        return 1;
    }
};