class Solution {
public:
    string reverseWords(string s) {
      reverse(s.begin(),s.end());
      vector<string>ans(1000);
      string temp;
      int count=0;
      for(int i=0;i<s.size();i++)
      {
        if(s[i]==' ')
        { if(!temp.empty()){
            reverse(temp.begin(),temp.end());
            ans[count]=temp;
            count++;
            temp.clear();
        }
         temp.clear();
        }else
        {
            temp+=s[i];

        }
      }
      if(!temp.empty()){
      reverse(temp.begin(),temp.end());
      ans[count]=temp;
      temp.clear();}

for(int i=0;i<=count;i++)
{
    temp+=ans[i];
    temp+=' ';
}
temp.pop_back();

if(temp[0]==' ')
{
}
if(temp[temp.size()-1]==' '){temp.pop_back();}

      return temp;
      }
    
};