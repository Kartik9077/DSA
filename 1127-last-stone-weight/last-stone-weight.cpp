class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>st;
        sort(stones.begin(),stones.end());
        for(auto it:stones)st.push(it);
        while(!st.empty()){
           int first=st.top();
           st.pop();
           if(st.empty())return first;
           int second=st.top();st.pop();
           if(first==second)continue;
           else {
            st.push(abs(first-second));
           }
        }
        return 0;

    
        
    }
};