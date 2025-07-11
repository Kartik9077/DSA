class Solution {
public:
    string removeStars(string s) {
        stack<char>st;string ans="";
        for(auto it:s){
            if(it=='*'&&!st.empty())st.pop();
            else st.push(it);
        }
        while(!st.empty()){
            char x=st.top();
            ans+=x;
            st.pop();

        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};