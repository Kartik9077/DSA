class Solution {
public:
    int secondHighest(string s) {
        int lar=-1,slar=-1;
        for(int i=0;i<s.size();i++){
            if(isdigit(s[i])){
                int x=s[i]-'0';
                if(x>lar){
                    slar=lar;
                    lar=x;
                }
                else if(x>slar&&x!=lar)slar=x;
            }
        }
        return slar;
        
    }
};