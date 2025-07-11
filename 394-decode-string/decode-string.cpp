class Solution {
public:
    string decodeString(string s) {
        stack<pair<string,int>>st;
        int num=0;
        string curr="";
        for(auto c:s){
            if(isdigit(c)){
                num*=10;
                num+=c-'0';
            }
            else if(c=='['){
                st.push(make_pair(curr,num));
                curr="";
                num=0;
            }
            else if(c==']'){
                string repeated="";
                int times=st.top().second;
                string last=st.top().first;
                st.pop();
                for(int i=0;i<times;i++){
                    repeated+=curr;
                }
                curr=last+repeated;
            }
            else{
                curr+=c;
            }

        }
        return curr;
        
        
    }
};