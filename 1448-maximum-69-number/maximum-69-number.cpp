class Solution {
public:
    int maximum69Number (int num) {
        int j=-1;
        if(num/10==0)return 9;
        string s=to_string(num);
        for(int i=0;i<s.size();i++)if(s[i]=='6'){j=i;break;}
        if(j==-1)return num;
       s[j]='9';
        num=stoi(s);
        return num;

    
        
    }
};