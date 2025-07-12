class Solution {
public:
bool check(int i,int j,string &s)
{
    if(i>=j)return 1;
    return s[i]==s[j]?check(i+1,j-1,s):0;
}
void solve(int idx,string&s,vector<string>&temp,vector<vector<string>>&res){
  if(idx==s.size()){res.push_back(temp);
  return;
  }
  for(int j=idx;j<s.size();j++){
    if(check(idx,j,s)){
        temp.push_back(s.substr(idx,j-idx+1));
        solve(j+1,s,temp,res);
        temp.pop_back();
    }
  }
}
    vector<vector<string>> partition(string s) {
        vector<vector<string>>res;
        vector<string>temp;
        solve(0,s,temp,res);
        return res;
    }
};