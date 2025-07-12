class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
 unordered_map<string,vector<string>>mpp;
 string key="";
    for(auto it:strs)
    { key=it;
        sort(key.begin(),key.end());
        if(mpp.find(key)!=mpp.end()){
            mpp[key].push_back(it);
        }
        else{
            mpp[key].push_back(it);
        }

    }
    for(auto it:mpp){
    ans.push_back(it.second);
    }
    return ans;

    }
};