class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        stack<pair<int,int>>st;
        vector<int>ans(t.size(),0);
        for(int i=t.size()-1;i>=0;i--){
            if(st.empty())st.push(make_pair(t[i],i));
            else {
              while(!st.empty()){
                if(st.top().first>t[i]){
                    ans[i]=st.top().second-i;
                    st.push({t[i],i});
                    break;
                }
                else st.pop();
              }
            }
            if(st.empty()){
            st.push({t[i],i});
        }
        }
        
        return ans;
        
    }
};