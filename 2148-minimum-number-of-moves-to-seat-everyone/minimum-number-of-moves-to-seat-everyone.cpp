class Solution {
public:
    int minMovesToSeat(vector<int>& se, vector<int>& st) {
        sort(se.begin(),se.end());
        sort(st.begin(),st.end());int req=0;
        for(int i=0;i<se.size();i++){
            req+=abs(st[i]-se[i]);

        }
        return req;
    }
};