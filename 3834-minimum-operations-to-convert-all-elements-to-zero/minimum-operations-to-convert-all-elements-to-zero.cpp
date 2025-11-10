class Solution {
public:
    int minOperations(vector<int>& nums) {
        stack<int>st;int ans=0;
        for(auto it:nums){
            while(!st.empty()&&st.top()>it){
                st.pop();
                ans++;
            }
            if(it>0 && (st.empty()||st.top()<it))st.push(it);

        }
        while(!st.empty()){
            st.pop();
            ans++;
        }
        return ans;
    }
};