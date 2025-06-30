class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& acc) {
        int n=acc.size();
        vector<vector<string>>ans;
        vector<int>v(n,0);
        set<string>st;
        for(int i=0;i<acc.size();i++){
            if(v[i]!=0)continue;
            vector<string>temp;
            temp.push_back(acc[i][0]);
            v[i]=-1;
          for(int j=1;j<acc[i].size();j++){
            st.insert(acc[i][j]);
            for(int k=i+1;k<n;k++){
                if(acc[k][0]!=acc[i][0])continue;
                if(v[k]!=0)continue;
                for(int p=1;p<acc[k].size();p++)
                {
                if(acc[i][j]==acc[k][p]){
                    v[k]=-1;
                    for(int l=1;l<acc[k].size();l++){
                        st.insert(acc[k][l]);
                        acc[i].push_back(acc[k][l]);
                    }
                    break;

                }
                }
            }}
            for(auto it:st){
                temp.push_back(it);
            }ans.push_back(temp);
          temp.clear();st.clear();
          }
        return ans;
    }
};