class Solution {
public:
  bool check(string a,string b){

    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    return a==b;
    
  }
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string>ans;
        stack<string>st;st.push(words[words.size()-1]);
       for(int i=words.size()-2;i>=0;i--){
        while(!st.empty()&&check(st.top(),words[i]))st.pop();
       st.push(words[i]);
       }
       while(!st.empty()){ans.push_back(st.top());st.pop();}
        return ans;
    }
};