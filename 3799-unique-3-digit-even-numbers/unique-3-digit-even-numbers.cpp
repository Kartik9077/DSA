class Solution {
public:
    int totalNumbers(vector<int>& d) {
   set<int>st;
    for(int i=0;i<d.size();i++){
        for(int j=0;j<d.size();j++){
            for(int k=0;k<d.size();k++){
                if(i!=j&&i!=k&&j!=k&&d[i]!=0&&d[k]%2==0){
                    st.insert(d[i]*100+d[j]*10+d[k]);
                }
            }
        }
    }
    return st.size();
    }
};