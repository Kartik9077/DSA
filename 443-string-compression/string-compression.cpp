class Solution {
public:
    int compress(vector<char>& chars) {
        string s="";
        s+=chars[0];int count=1;int i=0;int h=0;
        for( i=1;i<chars.size();i++){
            if(chars[i]==chars[h]){
                count++;
                continue;
            }
            else
            { if((count>1)){
                if(count<10){
                s+='0'+count;}
                else{
                    string spo=to_string(count);int p=0;
                    while(p<spo.length()){
                        s+=spo[p];
                    p++;
                    }
                }
            }
                h=i;count=1;
                s+=chars[i];
            }

            

        }
         if((count>1)){
                if(count<10){
                s+='0'+count;}
                else{
                    string sop=to_string(count);int p=0;
                    while(p<sop.length()){
                        s+=sop[p];
                    p++;
                    }
                }
            }
        
        chars.clear();
        int j=0;
        while(j<s.length()){
            
                chars.push_back(s[j]);
                j++;
            
        }
        return chars.size();


        
    }
};