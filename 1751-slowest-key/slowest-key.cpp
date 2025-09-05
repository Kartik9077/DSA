class Solution {
public:
    char slowestKey(vector<int>& re, string key) {
        char ans='0';int last_time=0;int maxii=0;
        for(int i=0;i<re.size();i++){
            int curr_time=re[i]-last_time;
            if(curr_time>=maxii){
                if(ans=='0')ans=key[i];
                else if(ans!='0'){
                    if(curr_time==maxii)
                    {
                        if(ans<key[i])ans=key[i];
                    }
                    else ans=key[i];
                }
                maxii=curr_time;

            }
            last_time=re[i];   
        }
        return ans;
        
    }
};