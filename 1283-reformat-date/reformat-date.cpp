class Solution {
public:
    string reformatDate(string date) {
         int l=date.length();
        string d="",m="",y="";
        int flag=0;
        string fun="";
        for(int i=0;i<l;i++)
        {
            string temp="";
            if(date[i]==' ')
            {
                i++;
                while(i<l && date[i]!=' ')
                {
                    temp.push_back(date[i]);
                    i++;
                }
                if(temp=="Oct")
                {
                    m="10";
                }
                else if(temp=="Jan")
                {
                    m="01";
                }
                else if(temp=="Feb")
                {
                    m="02";
                }
                else if(temp=="Mar")
                {
                    m="03";
                }
                else if(temp=="Apr")
                {
                    m="04";
                }
                else if(temp=="May")
                {
                    m="05";
                }
                else if(temp=="Jun")
                {
                    m="06";
                }
                else if(temp=="Jul")
                {
                    m="07";
                }
                else if(temp=="Aug")
                {
                    m="08";
                }
                else if(temp=="Sep")
                {
                    m="09";
                }
                else if(temp=="Dec")
                {
                    m="12";
                }
                else 
                {
                    m="11";
                }
                temp="";
                i++;
                while(i<l)
                {
                    temp.push_back(date[i]);
                    i++;
                }
                y+=temp;
            }
            else
            {
                fun.push_back(date[i]);
            }
        }
        string res="";
        res+=y;
        res.push_back('-');
        res+=m;
        res.push_back('-');
        cout<<fun;
        if(fun.length()==3)
        {
            res.push_back('0');
            res.push_back(fun[0]);
        }
        else
        {
            res.push_back(fun[0]);
            res.push_back(fun[1]);
        }
        return res;
    }
};